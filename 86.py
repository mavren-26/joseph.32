def fractional_knapsack(values, weights, W):
    items = sorted(zip(values, weights), key=lambda x: x[0]/x[1], reverse=True)
    total = 0
    for v, w in items:
        if W == 0:
            break
        take = min(w, W)
        total += take * v / w
        W -= take
    return total

# Driver code
if __name__ == "__main__":
    values = [60, 100, 120]
    weights = [10, 20, 30]
    W = 50
    print("Maximum value:", fractional_knapsack(values, weights, W))
