import test1


def list_human(name, age, score) :
    print('Name : ', name ,'Age : ', age, 'Score : ', score)

def action():
    str =test1.human(test1.name, test1.age, test1.score)
    return str

list_human(test1.name, test1.age, test1.score)

print(action())