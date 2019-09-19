"""
 Program:
    CS241 Team Activity 1, Read in a File
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
        
"""
def prompt_filename():
    filename = input("Enter file: ")
    
    return filename

#encoding = "utf-8"
#Counts the # of words and lines in the file.
def parse_file(filename):
    line_count = 0
    word_count = 0
    pride_count = 0
    with open(filename, "r") as file_in: # opens the file. 
        for line in file_in:
            # reads the file line by line.
            line_count += 1
            words = line.split() # Everytime when theres a space you will split
            # each word into a list.
            word_count += len(words) # Count the number of words in the list
            for word in words:
                if word == "pride":
                    pride_count += 1
                
    return (word_count, line_count, pride_count)

### Driver to test funtions
def main():
    filename = prompt_filename()
    (word_count, line_count, pride_count) = parse_file(filename)
    # Seperate the two values out of the tuple
    print("The file contains {} lines and {} words and {} pride." .format(line_count, word_count, pride_count))


if __name__ == "__main__":
    main()
    