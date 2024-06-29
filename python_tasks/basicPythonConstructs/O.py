hours = int(input())
minutes = int(input())
minutesToWait = int(input())

allMinutes = minutes + minutesToWait + hours * 60

finalHours = allMinutes // 60 % 24

finalMinutes = allMinutes % 60

lastHourDigit = finalHours % 10
firstHourDigit = finalHours // 10

lastMinutesDigit = finalMinutes % 10
firstMinutesDigit = finalMinutes // 10

time = str(firstHourDigit) + str(lastHourDigit) + ":" + str(firstMinutesDigit) + str(lastMinutesDigit)
print(time)