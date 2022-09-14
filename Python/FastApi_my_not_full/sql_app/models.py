from email.policy import default
from enum import unique
from sqlalchemy import Column, Integer, Boolean, String, ForeignKey  
from sqlalchemy.orm import relationship 

from .database import Base

class Student(Base):
    __tablename__ = "T_STUDENT"

    id = Column(Integer, primary_key=True, index=True)
    email = Column(String, index=True, unique=True)
    description = Column(String, index=True)
    is_active = Column(Boolean, default=True)

    posts = relationship("Post", back_populates="owner")

class Post(Base):
    __tablename__ = "T_POST"

    id = Column(Integer, primary_key=True,index=True)

    title = Column(String, index=True)
    description = Column(String, index=True)
    student_id = Column(Integer, ForeignKey("T_STUDENT.id"))

    owner = relationship("Student", back_populates="posts")

