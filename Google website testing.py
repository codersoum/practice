from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By
import time;
driver=webdriver.Chrome()
try :
    driver.get('https://www.google.com')
    searchbox=driver.find_element(By.NAME,"q")
    searchbox.send_keys("https://www.cmrcet.ac.in/")
    searchbox.send_keys(Keys.RETURN)
    time.sleep(20)
finally:
    driver.quit()



