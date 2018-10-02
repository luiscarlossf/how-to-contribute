message = input("Enter the message to decrypt with Caesar encryption: ")
message = message.upper()
shift = input("Enter the shift of the message: ")

finalString = ""

for x in message:
    newValue = ord(x)-int(shift)
    if(newValue < 65):
        newValue = newValue + 26
    finalString = finalString + chr(newValue)
    

print("Decrypt: "+str(finalString))
