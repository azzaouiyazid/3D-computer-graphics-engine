## University-Management-System Database 

## Table of contents

* [General info](#general-info)
* [Screenshots](#screenshots)
* [Setup](#setup)
* [Technologies](#technologies)
* [Project objectives](#project-objectives)

## Database Model 

* [Full schema](#Full-schema)
* [ER-Diagram](#ER-Diagram)






## General info
A simple University Management System database  created With Java Swing , JDBC , Sqlite.
the project is part of my second year database project at Zhejiang university of technology 

## Screenshots 
![table](https://user-images.githubusercontent.com/78693054/181716339-82d60804-9004-4109-8194-5f7786b04455.png)

![Screenshot 2022-05-02 155201](https://user-images.githubusercontent.com/78693054/195813512-ee874d81-b1d7-43f1-8229-40187bb56b4b.png)



## Setup
To run this project correctly , change the database location by modifying this line located in Sqlconnect.java :
![jdbc connection](https://user-images.githubusercontent.com/78693054/185797470-4de84542-0be3-45c0-ae0d-d8ae73ddf18d.png)

```
Connection conn = DriverManager.getConnection("jdbc:sqlite:C:\\Users\\Electro-Market.ma\\eclipse-workspace\\Ums\\yazid.db");
```
	
## Technologies
Project was created with:
* Sqlite JDBC version: 3.7.2
* JSE syteme liberary version: J2SE-1.5
* Sqlite version: 3.35.3

## Project objectives
this project will give a better understanding about : 

* Setting Up the Database
* manually register Java DB in the IDE
* Starting the Server and Creating a Database
* create the database
* Connecting to the Database
* Creating the Application
* Binding Controls to Values in the Table
* To bind the checkboxes to their corresponding table elements


## Full-schema
![Screenshot 2022-08-21 175123](https://user-images.githubusercontent.com/78693054/185801183-f06850db-3787-4460-8d5e-395509c26564.png)


## ER-Diagram
![E-R diagram ums](https://user-images.githubusercontent.com/78693054/185799159-edb89ff1-a187-4ea8-86a9-5e7d606c08b9.png)



