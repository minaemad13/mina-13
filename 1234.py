
print ("\t\twelcome kayles game")
y=[1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0]
x=0
while x<20:
    print( "player 1")
    a=int(input("how many number you want to choose 1 or 2? :-"))
    if a==1:
        print ("choose num from",y)
        plyer_1=int(input("=>"))
        y[plyer_1-1]="_"
        x+=1
        print (y)
    else:
        print ("choose 2 num from", y)
        plyer_1 = int(input("=>"))
        y[plyer_1 - 1] = "_"
        plyer_1 = int(input("=>"))
        y[plyer_1 - 1] = "_"
        x+=2
        print (y)
        
    if x==20:
        print ("player 2 is loser \n\n\tgame over")
        break
    print ("player 2")
    a=int(input("how many number you want to choose 1 or 2? :-"))
    if a==1:
        print ("choose num from",y)
        plyer_2=int(input("=>"))
        y[plyer_2-1]="_"
        x+=1
        print (y)
    else:
        print ("choose 2 num from", y)
        plyer_2 = int(input("=>"))
        y[plyer_2 - 1] = "_"
        plyer_2 = int(input("=>"))
        y[plyer_2 - 1] = "_"
        x+=2
        print (y)
    if x==20:
        print ("player 1 is loser \n\n\tgame over")
        break
