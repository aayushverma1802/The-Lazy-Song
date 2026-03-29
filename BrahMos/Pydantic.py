from pydantic import BaseModel

class Patient(BaseModel):
    name:str
    age:int

def insert_patient_data(patient:Patient):
    print(patient.name)
    print(patient.age)
    print("inserted")

patient_info={"age":"30","name":"nitish"}

patient1=Patient(**patient_info)
insert_patient_data(patient1)