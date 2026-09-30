text = input("Enter a paragraph: ")

characters = len(text)
spaces = text.count(" ")
words = len(text.split())

vowels = "aeiouAEIOU"
vowel_count = 0

for i in text:
    if i in vowels:
        vowel_count += 1

print("\n----- Text Analysis -----")
print("Total Characters :", characters)
print("Total Words      :", words)
print("Total Spaces     :", spaces)
print("Total Vowels     :", vowel_count)

if len(text) > 0:
    print("\nFirst Character (Indexing) :", text[0])
    print("Last Character (Indexing)  :", text[-1])

    print("\nFirst 10 Characters (Slicing) :", text[:10])
    print("Last 10 Characters (Slicing)  :", text[-10:])
