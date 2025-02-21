# Library Management System

## Overview
The **Library Management System** is a C# and SQL Server-based application designed to efficiently manage books, students, and authors. It streamlines library operations with a user-friendly interface and a robust backend for seamless data management.

## Features

### **Book Management**
- Add, update, and delete books.
- Store book details such as ISBN, title, genre, publication year, price, and available copies.
- Search for books by title.

### **Student Management**
- Add, update, and delete student records.
- Store student details including name, phone number, email, address, and birthdate.
- Search for students by name.

### **Author Management**
- Automatically link authors to books.
- Add new authors if they don’t exist in the database.

### **User-Friendly Interface**
- Developed using Windows Forms for a clean and intuitive experience.
- Data is displayed in grids for easy viewing and editing.

### **Database Integration**
- Uses **SQL Server** for data storage.
- Implements **ADO.NET** for database connectivity.
- Uses **parameterized queries** to prevent SQL injection and ensure security.

## Technologies Used
- **Programming Language:** C#
- **Frontend:** Windows Forms
- **Backend:** ADO.NET
- **Database:** SQL Server
- **Tools:** Visual Studio, SQL Server Management Studio (SSMS)

## Database Schema
The project consists of the following tables in the SQL Server database:

### **BOOK**
| Column       | Data Type     | Constraints       |
|-------------|--------------|------------------|
| ISBN        | BIGINT       | PRIMARY KEY     |
| Title       | NVARCHAR(100) | NOT NULL        |
| Genre       | NVARCHAR(50)  | NOT NULL        |
| PublishYear | INT          | NOT NULL        |
| Price       | BIGINT       | NOT NULL        |
| NumCopies   | INT          | NOT NULL        |

### **STUDENT**
| Column       | Data Type     | Constraints       |
|-------------|--------------|------------------|
| StudentID   | INT          | PRIMARY KEY     |
| Name        | NVARCHAR(100) | NOT NULL        |
| PhoneNumber | NVARCHAR(15)  | NOT NULL        |
| Email       | NVARCHAR(100) | NOT NULL        |
| Country     | NVARCHAR(50)  | NOT NULL        |
| City        | NVARCHAR(50)  | NOT NULL        |
| Street      | NVARCHAR(100) | NOT NULL        |
| BirthYear   | INT          | NOT NULL        |
| BirthMonth  | INT          | NOT NULL        |
| BirthDay    | INT          | NOT NULL        |
| Age         | INT          | NOT NULL        |

### **AUTHOR**
| Column    | Data Type     | Constraints       |
|----------|--------------|------------------|
| AuthorID | INT          | PRIMARY KEY, IDENTITY(1,1) |
| Name     | NVARCHAR(100) | NOT NULL        |

### **WRITE (Many-to-Many Relationship between BOOK and AUTHOR)**
| Column  | Data Type | Constraints |
|---------|----------|-------------|
| ISBN    | BIGINT   | FOREIGN KEY REFERENCES BOOK(ISBN) |
| AuthorID | INT     | FOREIGN KEY REFERENCES AUTHOR(AuthorID) |
| PRIMARY KEY | (ISBN, AuthorID) |

## Setup Instructions

### **Prerequisites**
- Install **Visual Studio** (Community edition is free).
- Install **SQL Server** and **SQL Server Management Studio (SSMS)**.

### **Database Setup**
1. Create a new database named `Library` in SQL Server.
2. Run the following SQL scripts to create the required tables:

```sql
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
```

### **Running the Project**
1. Clone the repository or download the source code.
2. Open the project in **Visual Studio**.
3. Update the connection string in the code to match your SQL Server instance:

```csharp
conn.ConnectionString = "data source = YOUR_SERVER_NAME; database = Library; integrated security = True";
```

4. Build and run the project in Visual Studio.


## Future Enhancements
- Implement **user authentication** (e.g., librarian vs. student roles).
- Add **book borrowing and return functionality**.
- Generate **reports and analytics** (e.g., most borrowed books, overdue books).
- Improve **UI/UX** with modern design elements.

