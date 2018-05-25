import subprocess
from subprocess import PIPE, STDOUT

output = open("test.out", "w")

ris = subprocess.Popen(executable="./a.out", args="", stdin=PIPE, stdout=output, stderr=STDOUT, universal_newlines=True, shell=True)

com = ris.stdin.write('1\n')
com = ris.stdin.write('84\n')

stockPrices = ['886\n', '2777\n', '6915\n', '7793\n', '8335\n', '5386\n', '492\n', '6649\n', '1421\n', '2362\n', '27\n', '8690\n', '59\n', '7763\n', '3926\n', '540\n', '3426\n', '9172\n', '5736\n', '5211\n', '5368\n', '2567\n', '6429\n', '5782\n', '1530\n', '2862\n', '5123\n', '4067\n', '3135\n', '3929\n', '9802\n', '4022\n', '3058\n', '3069\n', '8167\n', '1393\n', '8456\n', '5011\n', '8042\n', '6229\n', '7373\n', '4421\n', '4919\n', '3784\n', '8537\n', '5198\n', '4324\n', '8315\n', '4370\n', '6413\n', '3526\n', '6091\n', '8980\n', '9956\n', '1873\n', '6862\n', '9170\n', '6996\n', '7281\n', '2305\n', '925\n', '7084\n', '6327\n', '336\n', '6505\n', '846\n', '1729\n', '1313\n', '5857\n', '6124\n', '3895\n', '9582\n', '545\n', '8814\n', '3367\n', '5434\n', '364\n', '4043\n', '3750\n', '1087\n', '6808\n', '7276\n', '7178\n', '5788\n']

for x in stockPrices: 
    com = ris.stdin.write(x) 

# subprocess.call(["./a.out"])
