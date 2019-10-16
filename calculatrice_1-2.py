chiffre1 = float(input("Entrer le 1er chiffre du calcul: \n"))
signe = input("Type de calcul: \t \t (+,-,x,÷) \n")
chiffre2 = float(input("Deuxième chiffre du calcul: \n"))
if signe=="+" :
  print("Résultat:")
  print(chiffre1+chiffre2)
if signe=="-" :
  print("Résultat:")
  print(chiffre1-chiffre2)
if signe=="x" :
  print("Résultat:")
  print(chiffre1*chiffre2)
if signe=="*" :
  print("Résultat:")
  print(chiffre1*chiffre2)
if signe=="/" :
  print("Résultat:")
  print(chiffre1/chiffre2)
