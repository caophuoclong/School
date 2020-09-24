import requests
url = "https://htql.ctu.edu.vn/htql/login.php"

reponse = requests.get(url)
print(reponse)