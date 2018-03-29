def main():
    word=input("please enter a string to find biggest palindrom: ")
    biggest=1
    big=word[0]
    

    for i in range(len(word)): 
        for t in range(len(word),i+1,-1):
            if(t-i<biggest):
                break
            if(findPal(word[i:t])):
                if(t-i>biggest):
                    biggest=t-i
                    big=word[i:t]




    print("The biggest substring plaindrom is "+str(big)+" with a count of "+str(biggest))
   
               
           



def findPal(string):
	if(string[::-1]==string):
		return True
	else:
		return False
main()   
