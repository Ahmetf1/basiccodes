import urllib.request, urllib.parse, urllib.error
import sqlite3
from bs4 import BeautifulSoup
from datetime import datetime
aurl="""https://www.monsternotebook.com.tr/"""
conn = sqlite3.connect("dbmonster.sqlite")
cur = conn.cursor()
time=datetime.now()
 
cur.execute('DROP TABLE IF EXISTS LINKS')
cur.execute(f'''
CREATE TABLE LINKS (HREF TEXT UNIQUE)''')

  

class Search:
    def __init__(self,key):
        self.key=key 
        self.links=[]
        self.models=[]       
    def lookup(self):    
        url=aurl+"/"+self.key
        html=urllib.request.urlopen(url).read()
        soup=BeautifulSoup(html,"html.parser")
        for x in soup.find_all('a',{"class":"ems-prd-lnk"}):
            self.links.append(aurl+x.get("href"))
            print(x.get("href"))
    def save(self):
        for x in self.links:       
            cur.execute('''INSERT OR IGNORE INTO LINKS(HREF)
                    VALUES (?)''', (x,))
        conn.commit()                                
    def login(self):
        cur.execute("""SELECT HREF FROM LINKS""")
        arr=cur.fetchall()
        for x in arr:
            html=urllib.request.urlopen(x[0]).read()
            soup=BeautifulSoup(html,"html.parser")
            price1=soup.find("span",{"class":"urunDetay_satisFiyat"}).text
            prices=price1.split()
            price=prices[0]            
            cur.execute(f'''INSERT OR IGNORE INTO {Table} (HREF,Price)
                    VALUES (?,?)''', (x[0],price))
            print(price)        
            conn.commit()    
        
                   

   
while True:
    h=input(f"Hoşgeldiniz tarih ve saat:{time}\nLütfen yapmak istediğiniz işlemi seçiniz\n1-Modelleri içe aktar\n2-Fiyatları içe aktar\n3-Veritabanını görüntüle\n4-Çıkış yap\n")
    if h =="1":
        modelx=input("hangi model ?\n abra or tulpar or semruk:")
        model=Search(modelx)
        model.lookup()
        model.save()
    if h =="2":
        print(time)
        Table=input("Table Name:")
        cur.execute(f'''
                    CREATE TABLE {Table} (HREF TEXT UNIQUE,Price INTEGER)''')
        model.login()
    if h=="3":
        table_name=input("table name:")
        cur.execute(f"SELECT * FROM {table_name}")
        H=cur.fetchall()
        for x in H:
            print(x)
    if h=="4":
        break

