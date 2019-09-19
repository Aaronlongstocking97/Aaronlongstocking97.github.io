"""
 Program:
    CS241 Assignment 02, Read in a File
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
     This program will take in the filename from the users input and display 
     the results for the average mean, low rate, and high rate. Once the file
     is given the parse_file function will convert the data to a list and read 
     it line by line until it reaches the end. While the file is in a list it can 
     then be called by the indidual column for the commercial rate and have the 
     calculations done to find the mean rate, low rate and high rate.
        
"""
def prompt_filename():
    filename = input("Please enter the data file: ")
    print()
    
    return filename


def parse_file(filename):
    comm_rate = 0
    high_rate = 0
    low_rate = 0
    mean = 0
    line_count = 0
    highest = 0
    lowest = 1
    with open(filename, "r") as file_in:  # opens the file.
        next(file_in)                     # skips the line
        for line in file_in:              # reads the file line by line.
            data = line.split(",")        # Converts to a data list.
            comm_rate += float(data[6])   # get the sum rate each time 
            high_rate = float(data[6])    # the loop passes through.
            low_rate = float(data[6])
            line_count += 1 
            if high_rate > highest:
                highest = high_rate
                high_zip = data[0]
                high_company = data[2]
                high_state = data[3]
            if low_rate < lowest:
                lowest = low_rate
                low_zip = data[0]
                low_company = data[2]
                low_state = data[3]
    # Once the for loop is terminated you can then sum everything together
    # and divide it by the line_count
    mean = comm_rate / line_count
    print("The average commercial rate is: {}" .format(mean))
    print()
    print("The highest rate is:\n{} ({}, {}) - ${}" .format(high_company, high_zip,
                                                           high_state, highest))
    print()
    print("The lowest rate is:\n{} ({}, {}) - ${}" .format(low_company, low_zip,
                                                          low_state, lowest))
    
   
    
### Driver to test funtions
def main():
    
    filename = prompt_filename()
    parse_file(filename)
    

if __name__ == "__main__":
    main()
    
