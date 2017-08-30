hw2 folder contains the following files 
      1.main.cpp- the program file
      2.stud_db.pro-qt creator project file
      3.test.txt- sample input for student database
      4.readme.txt

To compile the program:

               g++ main.cpp -o main.out 

Add execute permission to object file:

               chmod +x main.out

To run the program:

               ./main.out

To test the program:

1. Add a few student records using option 1 on menu (Alternatively load from sample file provided - test.txt)
2. You can test validations for input fields (e.g. id > 9 chars)
3. Use the menu to test modify, delete, print.. etc on student records.
4. To save students to file, provide the name of the file which will be created in the same folder.
