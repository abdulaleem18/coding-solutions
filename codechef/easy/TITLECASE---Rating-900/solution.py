T = int(input())

for _ in range(T):
    S = input()
    words = S.split()
    result = []

    for word in words:
        if word.isupper():
            result.append(word)
        else:
            result.append(word[0].upper() + word[1:].lower())

    print(" ".join(result))