"""
 Program:
    CS241 Data Structures assign 04, Student Help Center
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
    
    The strategy is that for every opening brace that I put on the stack,
    there should be a closing brace that matches it to pop off.

    So, if I have { [ ( ) ] }
    Then I will push {, [, and ( onto the stack.
    When I see a closing ), then I should see a
    ( popped off the stack. If I get something else,
    then the the braces are not ordered properly. If the
    stack is empty, then I'm missing a brace.
    
"""

filename = input("File: ")
braces = []
balanced = True
with open(filename, "r") as fileIn:
    for brace in fileIn: # Read each line
        brace = brace.strip() # Remove whitespace
        if (brace == "{") or (brace == "(") or (brace == "["):
            braces.append(brace) # Push open brace onto the stack
        else:
            if (len(braces) == 0): # Close brace received but empty stack
                balanced = False
                break
        # Pop off stack and check for mismatch between open and close brace
        prev_brace = braces.pop()
        if (((brace == "}") and (prev_brace != "{")) or
            ((brace == ")") and (prev_brace != "(")) or
            ((brace == "]") and (prev_brace != "["))):
            balanced = False
            break

# Stack should now be empty. If it is not, then not balanced.
if (len(braces) != 0) or (not balanced):
    print("Not balanced")
else:
    print("Balanced")
    
    
    