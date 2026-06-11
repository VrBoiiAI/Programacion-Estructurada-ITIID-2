import numpy as np
import matplotlib.pyplot as plt
import subprocess
subprocess.run("clear")
"""
Y = np.piecewise(
    X,
    [X < a, (X >= a) & (X <= m), (X > m) & (X <= b), X > b], ## Alternative to np.select()
    [
        0,
        lambda x: (x - a) / (m - a),
        lambda x: (b - x) / (b - m),
        0,
    ],
)
"""
def plot(x, Limits, Functions, f):
    Y = np.select(Limits, Functions)

    plt.figure(figsize=(8, 5))
    plt.plot(X, Y)

    y = np.interp(x, X, Y)
    plt.vlines(x, 0, 1, colors="red", linestyles="dashed", label=f"Value of x in {x} (f(x)={round(y,2)})")

    plt.title(f'{f} function')
    plt.xlabel("X")
    plt.ylabel("Y")
    plt.legend()
    plt.grid(True, linestyle="--", alpha=0.7)
    plt.show()

op = input("\n[1] Triangular Function\n[2] Gamma Function\n[3] Trapezoidal Function\n[4] S Function\n\nWhich function do you want to represent?: ")

match op:
    case "1":
        a = int(input("Enter the value of a (start of the upward slope): "))
        m = int(input("Enter the value of m (peak of the triangle): "))
        b = int(input("Enter the value of b (end of the downward slope): "))
        if (a < m and m < b):
            x = int(input("Enter the value of x to calculate: "))
            if x <= a:
                print(f'The value of x in {x} is: 0')
            elif x <= m:
                print(f'The value of x in {x} is: {(x-a)/(b-m)}')
            elif x <= b:
                print(f'The value of x in {x} is: {(b-x)/(b-m)}')
            else:
                print(f'The value of x in {x} is: 0')
            

            X = np.linspace(a-1, b+1, 200)
            plot(x, [X <= a, (X > a) & (X <= m), (X > m) & (X <= b), X > b], [0, (X - a) / (m - a), (b - X) / (b - m), 0], "Triangular")

        else:
            print("The values of the limits dont match (should be a<m<b)")

    case "2":
        a = int(input("Enter the value of a (start of the upward slope): "))
        m = int(input("Enter the value of m (end of the upward slope): "))
        if a < m:
            x = int(input("Enter the value of x to calculate: "))
            if x <= a:
                print(f'The value of x in {x} is: 0')
            elif x < m:
                print(f'The value of x in {x} is: {(x-a)/(m-a)}')
            else:
                print(f'The value of x in {x} is: 1')

            X = np.linspace(a-1, m+1, 200)
            plot(x, [X <= a, (X > a) & (X < m), X >= m], [0, (X - a) / (m - a), 1], "Gamma")

        else:
            print("The values of the limits dont match (should be a < m)")

    case "3":
        a = int(input("Enter the value of a (start of the upward slope): "))
        b = int(input("Enter the value of b (end of the upward slope): "))
        c = int(input("Enter the value of c (start of the downward slope): "))
        d = int(input("Enter the value of d (end of the downward slope): "))
        if a < b and b < c and c < d:
            x = int(input("Enter the value of x to calculate: "))
            if (x <= a):
                print(f'The value of x in {x} is: 0')
            elif x <= b:
                print(f'The value of x in {x} is: {(x-a)/(b-a)}')
            elif x <= c:
                print(f'The value of x in {x} is: 1')
            elif x <= d:
                print(f'The value of x in {x} is: {(d-x)/(b-c)}')
            else:
                print(f'The value of x in {x} is: 0')

            X = np.linspace(a-1, d+1, 200)
            plot(x, [X<=a, (X>a)&(X<=b), (X>b)&(X<=c), (X>c)&(X<=d), X>d], [0,(X-a)/(b-a),1,(d-X)/(d-c),0], "Trapezoidal")
            
        else:
            print("The values of the limits dont match (should be a<b<c<d)")

    case "4":
        a = int(input("Enter the value of a (start of the slope): "))
        c = int(input("Enter the value of c (end of the slope): "))
        if a < c:
            x = int(input("Enter the value of x to calculate: "))
            if x < a:
                print(f'The value of x in {x} is: 0')
            elif x <= ((a+c)/(2)):
                print(f'The value of x in {x} is: {(2*(((x-a))/(c-a))**2)}')
            elif x <= c:
                print(f'The value of x in {x} is: {(1-(2*((c-x)/(c-a))**2))}')
            else:
                print(f'The value of x in {x} is: 1')

            X = np.linspace(a-1, c+1, 200)
            plot(x, [X<=a, (X>a)&(X<=((a+c)/(2))), (X>((a+c)/(2)))&(X<=c), X>c], [0, (2*(((X-a))/(c-a))**2), (1-(2*((c-X)/(c-a))**2)), 1], "S")

        else:
            print("The values of the limits dont match (should be a<c)")