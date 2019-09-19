"""
 Program:
    CS241 Checkpoint 02B, Read in a File
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
        
"""
#Counts the # of words and lines in the file.
def read_file(filename):
    line_count = 0
    word_count = 0
    with open(filename, "r") as file_in: # opens the file. 
        for line in file_in: # reads the file line by line.
            line_count += 1
            words = line.split() # Everytime when theres a space you will split
            # each word into a list.
            word_count += len(words) # Count the number of words in the list
    return (word_count, line_count)

### Driver to test funtions
def main():
    filename = input("Enter file: ")
    (word_count, line_count) = read_file(filename) # Seperate the two values out of the
    #tuple
    print("The file contains {} lines and {} words." .format(line_count, word_count))

if __name__ == "__main__":
    main()
    