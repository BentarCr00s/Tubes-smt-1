import threading
import itertools

# fungsi yang akan dijalankan oleh thread 
def generate_wordlist(charset, length):
    result = itertools.product(charset, repeat=length)
    with open('wordlist.txt', 'a') as f:
        for i in result:
            f.write(''.join(i)+'\n')

# menentukan karakter yang akan digunakan
charset = "abcdefghijklmnopqrstuvwxyz0123456789"
# menentukan panjang karakter
length = 7

# membuat thread
t1 = threading.Thread(target=generate_wordlist, args=(charset, length))

# menjalankan thread
t1.start()