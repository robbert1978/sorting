import random
max_=20
def generator_arr():
    arr_=[]
    for i in range(1_000_000):
        arr_.append(round(random.uniform(5,max_), 5))
    return arr_
def write_file(file_name,arr_):
    f=open(file_name,"w")
    print(*arr_,file=f,sep='\n')
    f.close()
for i in range(1,11):
    arr_=generator_arr()
    if i==1:
        arr_.sort()
    elif i==2:
        arr_.sort()
        arr_.reverse()
    write_file("{}_test.txt".format(i),arr_)