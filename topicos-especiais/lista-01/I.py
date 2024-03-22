from datetime import date, timedelta, datetime

cases = int(input())
cont = 1

while cases:
    inp = input().replace("\r", "")

    data = datetime.strptime(inp, "%Y-%B-%d").date()
    dias = int(input())
    data += timedelta(days=dias)

    print("Case %d: %s"%(cont, data.strftime("%Y-%B-%d")))
    cont +=1

    
    cases -= 1
