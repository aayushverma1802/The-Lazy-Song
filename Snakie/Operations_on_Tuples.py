countries=("Spain,","Italy","India","England",
           "Germany")

temp=list(countries)
temp.append("Russia")
temp.pop()
temp[2]="Finland"
countries=tuple(temp)
print(countries)

