def main():
    
    
    number= int(input("Enter In a Number less than 3000 to be changed to Roman Numeral: "))
    while(number>0):
        roman=convertRoman(number)
        print(roman+"\n")
        print("To quit enter a number 0 or less\n")
        number = int(input("Enter In a Number less than 3000 to be changed to Roman Numeral: "))
       



def convertRoman(number):
    arb = (1000, 900,  500, 400, 100,  90, 50,  40, 10,  9,   5,  4,   1)
    ro = ('M',  'CM', 'D', 'CD','C', 'XC','L','XL','X','IX','V','IV','I')
    result =[];
    for i in range(len(arb)):
        count = int(number / arb[i])
        result.append(ro[i] * count)
        number -= arb[i] * count
    return ''.join(result)





    
main()    
