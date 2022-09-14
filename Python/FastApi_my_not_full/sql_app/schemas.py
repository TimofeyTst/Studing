from pydantic import BaseModel

class PostBase(BaseModel):
    title: str
    description: str | None = None

class PostCreate(PostBase):
    pass

class Post(PostBase):
    id: int
    student_id: int

    class Config:
        orm_mode = True
    

class StudentBase(BaseModel):
    email: str
    description: str | None = None

class StudentCreate(StudentBase):
    pass

class Student(StudentBase):
    id: int
    is_active: bool
    posts: list[Post] = []

    class Config:
        orm_mode = True
