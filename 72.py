def marked_price(cp, profit_percent, discount_percent):
    sp = cp * (1 + profit_percent / 100)
    mp = sp / (1 - discount_percent / 100)
    return mp

cp = 800
profit = 25
discount = 10

mp = marked_price(cp, profit, discount)
print("Required Marked Price:", mp)
