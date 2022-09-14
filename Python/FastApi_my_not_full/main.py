from fastapi import FastAPI, status, HTTPException, Depends
from sqlalchemy.orm import Session

from sql_app import models, schemas

from sql_app import crud
from sql_app.database import SessionLocal, engine

models.Base.metadata.create_all(bind=engine)
app = FastAPI()

def get_db():
    db = SessionLocal()
    try:
        yield db
    finally:
        db.close()
        

@app.post('/students', response_model=schemas.Student)
def create_student(student: schemas.StudentCreate, db: Session = Depends(get_db)):
    db_student = crud.get_student_by_email(db, email=student.email)
    if db_student:
        raise HTTPException(status_code=status.HTTP_400_BAD_REQUEST, detail=f"User with email={student.email} already registered")
    return crud.create_student(db=db, student=student)

@app.post('/student/{student_id}/posts', response_model=schemas.Post)
def create_post(student_id: int, post: schemas.PostCreate, db: Session = Depends(get_db)):
    db_student = crud.get_student(db, student_id=student_id)
    if not db_student:
        raise HTTPException(status_code=status.HTTP_400_BAD_REQUEST, detail=f"User with id={student_id} wasn`t found")
    return crud.create_post(db, post, student_id)

@app.get('/students', response_model=list[schemas.Student])
def get_students(skip: int=0, limit: int=100, db: Session = Depends(get_db) ):
    db_students = crud.get_students(db, skip, limit)
    if not (db_students):
        raise HTTPException(status_code=status.HTTP_404_NOT_FOUND, detail="There`s no Students in database")
    return db_students

@app.get('students/{id}', response_model=schemas.Student)
def get_student(id: int, db: Session = Depends(get_db)):
    db_student = crud.get_student(db, id)
    if not db_student:
        raise HTTPException(status_code=status.HTTP_404_NOT_FOUND, detail=f"User with id={id} wasn`t found")
    return db_student

# @app.get('/students/{email}', response_model=schemas.Student)
# def get_student_by_email(email: str, db: Session = Depends(get_db)):
#     db_student = crud.get_student_by_email(db, email)
#     if not db_student:
#         raise HTTPException(status_code=status.HTTP_404_NOT_FOUND, detail=f"User with email={email} wasn`t found")
#     return db_student

@app.get('/students/{student_id}/posts', response_model=list[schemas.Post])
def get_student_posts(student_id: int, skip: int=0, limit: int=100, db: Session = Depends(get_db)):
    db_posts = crud.get_student_posts(db, student_id, skip, limit)
    if not db_posts:
        raise HTTPException(status_code=status.HTTP_404_NOT_FOUND, detail=f"Not found posts for student with id={student_id}")
    return db_posts

@app.get('students/{student_id}/posts/{post_id}', response_model=schemas.Post)
def get_student_post(student_id: int, post_id: int, db: Session = Depends(get_db)):
    db_post = crud.get_student_post(db, student_id, post_id)
    if not db_post:
        raise HTTPException(status_code=status.HTTP_404_NOT_FOUND, detail="Not found TST")
    return db_post

