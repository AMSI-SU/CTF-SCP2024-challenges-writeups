from pwn import *
import requests
from bs4 import BeautifulSoup
import re
import time

def find_movie_url(movie_name):
    search_query = movie_name.replace(" ", "%20")
    url = f"https://www.themoviedb.org/search?query={search_query}"

    try:
        response = requests.get(url)
        if response.status_code == 200:
            soup = BeautifulSoup(response.content, 'html.parser')
            divs = soup.find_all('div', class_='title')
            
            for div in divs:
                h2 = soup.find('h2')
                if movie_name.lower() in h2.text.strip().lower():
                    link = div.find('a')['href']
                    return "https://www.themoviedb.org" + link
    except Exception as e:
        print(f"Erreur lors de la recherche de l'URL du film {movie_name}: {e}")
    
    return None

def get_movie_rating(movie_url):
    try:
        response = requests.get(movie_url)
        if response.status_code == 200:
            soup = BeautifulSoup(response.content, 'html.parser')
            user_score = soup.find('div', class_='user_score_chart')
            if user_score:
                return user_score['data-percent']
    except Exception as e:
        print(f"Erreur lors de la récupération de la note pour {movie_url}: {e}")
    
    return None

# Connexion au serveur
# server = process(["python3", "movie_scrap_server_bs.py"])
# Pour une connexion distante, utilisez : 
server = remote('amsi-sorbonne.fr', 4005)

# Lire l'intro du serveur
# print(server.recvuntil(b'Film 10 : OK').decode())

for i in range(10):  # Il y a 10 films à deviner
    # Lire la question (nom du film)
    line = server.recvuntil(b'Note :').decode()
    print(line)  # Afficher la question pour debug
    
    # Extraire le nom du film
    match = re.search(r'Quel est la note des spectateurs pour le film "(.*)" \?', line)
    if not match:
        print("Erreur : impossible d'extraire le nom du film.")
        break

    movie_name = match.group(1)
    print(f"Recherche de la note pour : {movie_name}")
    
    # Chercher la note en ligne
    movie_url = find_movie_url(movie_name)
    rating = get_movie_rating(movie_url)

    if not rating:
        print(f"Erreur : impossible de trouver la note pour {movie_name}.")
        break

    print(f"Note trouvée : {rating}")
    
    # Envoyer la réponse
    server.sendline(rating.encode())

# Lire la fin du jeu
print(server.recvall().decode())
