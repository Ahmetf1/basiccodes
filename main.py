import cv2
import os


def get_image_difference(image_1, image_2):
    first_image_hist = cv2.calcHist([image_1], [0], None, [256], [0, 256])
    second_image_hist = cv2.calcHist([image_2], [0], None, [256], [0, 256])

    img_hist_diff = cv2.compareHist(first_image_hist, second_image_hist, cv2.HISTCMP_BHATTACHARYYA)
    img_template_probability_match = cv2.matchTemplate(first_image_hist, second_image_hist, cv2.TM_CCOEFF_NORMED)[0][0]
    img_template_diff = 1 - img_template_probability_match

    # credit:https://stackoverflow.com/questions/11541154/checking-images-for-similarity-with-opencv
    # taking only 10% of histogram diff, since it's less accurate than template method
    commutative_image_diff = (img_hist_diff / 10) + img_template_diff
    return commutative_image_diff


if __name__ == "__main__":
    cwd = os.getcwd()
    save_path = os.path.join(cwd,"save")
    try:
        os.makedirs(save_path)
    except:
        pass
    videos = os.listdir(cwd)

    idx_video = int(input(f"files in the directory are {videos}\n"
                          f"your video index(1,2,3... ?) : ")) - 1
    threshold = float(input("threshold (default 0.1):"))
    print(videos[idx_video])
    vidcap = cv2.VideoCapture(videos[idx_video])
    success, image = vidcap.read()
    count = int(0)

    while success:
        if count == 0:
            old_image = image
            pass
        new_image = image
        error = get_image_difference(old_image, new_image)
        count += 1
        old_image = image
        success, image = vidcap.read()
        if error > threshold:
            print(error)
            cv2.imwrite(os.path.join(save_path, "frame%d.jpg" % count), old_image)




