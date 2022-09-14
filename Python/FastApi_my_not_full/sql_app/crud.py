from sqlalchemy.orm import Session

from . import schemas

from . import models

def create_student(db: Session, student: schemas.StudentCreate):
    db_student = models.Student(**student.dict())
    db.add(db_student)
    db.commit()
    db.refresh(db_student)
    return db_student

def create_post(db: Session, post: schemas.PostCreate, student_id: int):
    db_post = models.Post(**post.dict(), student_id=student_id)
    db.add(db_post)
    db.commit()
    db.refresh(db_post)
    return db_post

def get_students(db: Session, skip: int=0, limit: int=100):
    return db.query(models.Student).offset(skip).limit(limit).all()

def get_student(db: Session, student_id: int):
    return db.query(models.Student).filter(models.Student.id == student_id).first()

def get_student_by_email(db: Session, email: str):
    return db.query(models.Student).filter(models.Student.email == email).first()

def get_student_posts(db: Session, student_id: int, skip: int=0, limit: int=100):
    return db.query(models.Post).filter(models.Post.student_id == student_id).offset(skip).limit(limit).all() #FIXME try without all()

def get_student_post(db: Session, student_id: int, post_id: int):
    return db.query(models.Post).filter(models.Post.student_id == student_id, models.Post.id == post_id).first()



