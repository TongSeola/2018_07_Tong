def readScoreDB():
    try:
        fH = open(dbfilename, 'rb')
    except FileNotFoundError as e:
        print("New DB: ", dbfilename)
        return []

    scdb = []                                #scdb is test3_4.py read and make pickle
    try:
        scdb = pickle.load(fH)
    except:
        print("Empty DB: ", dbfilename)
    else:
        print("Open DB: ", dbfilename)
    fH.close()
    return scdb

def writeScoreDB(scdb):                               # write the data into person db
    fH = open(dbfilename, 'wb')
    pickle.dump(scdb, fH)
    fH.close()


def doScoreDB(scdb):                                       #input and infinite
    while (True):
        inputstr = (input("Score DB >"))
        if inputstr == "": continue
        parse = inputstr.split(" ")

        if sender.text() == 'Add':
            Erro_len(4,parse)
            try:
                parse[3] or parse[2]
            except:
                print("Please, enter Name Age Score")
            else:
                record = {'Name': parse[1], 'Age': parse[2], 'Score': parse[3]}
                scdb += [record]

        elif parse[0] == 'del':
             Erro_len(2,parse)
             for k in range(0, len(scdb)):
                 for p in (scdb):
                    if p['Name'] == parse[1]:
                        scdb.remove(p)

        elif parse[0] == 'show':
#             Erro_len(2,parse)
             try:
                 sortKey = 'Name' if len(parse) == 1 else parse[1]
                 showScoreDB(scdb, sortKey)
             except:
                 for p in scdb:
                     if p['Name'] != parse[1] or p['Age'] != parse[1] or p['Score'] != parse[1]:
                         print("Please, enter right spelling")
                         break

        elif parse[0] == 'find':
            try:
                Erro_len(2,parse)
                dic_find = []
            except:
                try:
                    for p in scdb:
                        if p['Name'] == parse[1]:
                            dic_find += [p]
                        sortKey = 'Name'
                    showScoreDB(dic_find, sortKey)
                except:
                    print("Please, enter Name")

        elif parse[0] == 'inc':
            try:
                Erro_len(3,parse)
            except:
                try:
                    for p in scdb:
                        if p['Name'] == parse[1]:
                            p['Score'] = str(int(p['Score']) + int(parse[2]))
                            break
#                        elif p['Name'] != parse[1]:
#                            print("Please, enter right Name")
#                            break
                except:
                    print("Please, enter Name and Score")

        elif parse[0] == 'quit':                          #stop
            break

        else:
            print("Invalid command: " + parse[0])


def showScoreDB(scdb, keyname):                           #show scdb
    for p in sorted(scdb, key=lambda person: person[keyname]):
        for attr in sorted(p):
            print(attr + "=" + p[attr], end=' ')
        print()

def Erro_len(length, parse):
    while len(parse)>length :
        print("Please, enter suitable sentence")
        break

scoredb = readScoreDB()
doScoreDB(scoredb)
writeScoreDB(scoredb)