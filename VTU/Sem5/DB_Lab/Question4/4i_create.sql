CREATE DATABASE BOOK;
USE BOOK;
CREATE TABLE IF NOT EXISTS AUTHOR
( authorid INTEGER(8) PRIMARY KEY,
  aname  VARCHAR(25),
  acity  VARCHAR(15),
  acountry VARCHAR(15)
);

CREATE TABLE IF NOT EXISTS PUBLISHER
( publisherid INTEGER(8) PRIMARY KEY,
  pname  VARCHAR(25),
  pcity  VARCHAR(15),
  pcountry VARCHAR(15)
);

CREATE TABLE IF NOT EXISTS CATEGORY 
( categoryid INTEGER(8) PRIMARY KEY,
  description VARCHAR(25)
);

CREATE TABLE IF NOT EXISTS CATALOG
( bookid INTEGER(8) PRIMARY KEY,
  title  VARCHAR(25),
  authorid INTEGER(8) REFERENCES AUTHOR(authorid),
  publisherid INTEGER(8) REFERENCES PUBLISHER(publisherid),
  categoryid INTEGER(8) REFERENCES CATEGORY(categoryid),
  year  INTEGER(4),
  price  DECIMAL(6,2)
);

CREATE TABLE IF NOT EXISTS ORDER_DETAILS
( orderno INTEGER(8) PRIMARY KEY,
  bookid INTEGER(8) REFERENCES CATALOG(bookid),
  quantity INTEGER(8)
);
