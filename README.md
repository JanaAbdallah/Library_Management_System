Library Management System
Library Management System
Library Management System
Library Management System

A Library Management System built using C# and SQL Server to manage books, students, and authors efficiently. This project is designed to streamline library operations with a user-friendly interface and robust backend functionality.

Features
Book Management:

Add, update, and delete books.

Store book details like ISBN, title, genre, publication year, price, and number of copies.

Search for books by title.

Student Management:

Add, update, and delete student records.

Store student details like name, phone number, email, address, and birthdate.

Search for students by name.

Author Management:

Automatically link authors to books.

Add new authors if they don’t already exist in the database.

User-Friendly Interface:

Built using Windows Forms for a clean and intuitive experience.

Data displayed in grids for easy viewing and editing.

Database Integration:

Uses SQL Server for data storage.

Implements ADO.NET for database connectivity.

Uses parameterized queries to prevent SQL injection and ensure security.

Technologies Used
Programming Language: C#

Frontend: Windows Forms

Backend: ADO.NET

Database: SQL Server

Tools: Visual Studio, SQL Server Management Studio (SSMS)

Database Schema
The project uses the following tables in the SQL Server database:

BOOK:

ISBN (Primary Key)

Title

Genre

PublishYear

Price

NumCopies

STUDENT:

StudentID (Primary Key)

Name

PhoneNumber

Email

Country

City

Street

BirthYear

BirthMonth

BirthDay

Age

AUTHOR:

AuthorID (Primary Key)

Name

WRITE (Many-to-Many Relationship between BOOK and AUTHOR):

ISBN (Foreign Key)

AuthorID (Foreign Key)

How to Set Up the Project
Prerequisites
Visual Studio: Install Visual Studio (Community edition is free).

SQL Server: Install SQL Server and SQL Server Management Studio (SSMS).

Database Setup:

Create a database named Library in SQL Server.

Run the following SQL scripts to create the required tables:

sql
Copy
CREATE TABLE BOOK (
    ISBN BIGINT PRIMARY KEY,
    Title NVARCHAR(100),
    Genre NVARCHAR(50),
    PublishYear INT,
    Price BIGINT,
    NumCopies INT
);

CREATE TABLE STUDENT (
    StudentID INT PRIMARY KEY,
    Name NVARCHAR(100),
    PhoneNumber NVARCHAR(15),
    Email NVARCHAR(100),
    Country NVARCHAR(50),
    City NVARCHAR(50),
    Street NVARCHAR(100),
    BirthYear INT,
    BirthMonth INT,
    BirthDay INT,
    Age INT
);

CREATE TABLE AUTHOR (
    AuthorID INT PRIMARY KEY IDENTITY(1,1),
    Name NVARCHAR(100)
);

CREATE TABLE WRITE (
    ISBN BIGINT FOREIGN KEY REFERENCES BOOK(ISBN),
    AuthorID INT FOREIGN KEY REFERENCES AUTHOR(AuthorID),
    PRIMARY KEY (ISBN, AuthorID)
);
Steps to Run the Project
Clone the repository or download the source code.

Open the project in Visual Studio.

Update the connection string in the code to match your SQL Server instance:

csharp
Copy
conn.ConnectionString = "data source = YOUR_SERVER_NAME; database = Library; integrated security = True";
Build and run the project in Visual Studio.

Screenshots
Main Dashboard
Dashboard

Book Management
Book Management

Student Management
Student Management

Future Enhancements
Add user authentication (e.g., librarian vs. student roles).

Implement book borrowing and return functionality.

Add reports and analytics (e.g., most borrowed books, overdue books).

Improve UI/UX with modern design elements.

Contributing
Contributions are welcome! If you'd like to contribute, please:

Fork the repository.

Create a new branch for your feature or bugfix.

Submit a pull request.

License
This project is licensed under the MIT License. See the LICENSE file for details.

Contact
If you have any questions or suggestions, feel free to reach out:

LinkedIn: Your LinkedIn Profile

Email: your.email@example.com
