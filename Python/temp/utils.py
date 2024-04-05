import json
import os


def load_students():
    """Загружает список студентов из файла
    """
    with open(os.path.join('data', 'students.json'), 'r') as file:
        students = json.load(file)
        return students


def load_professions():
    """Загружает список профессий из файла
    """
    with open(os.path.join('data', 'professions.json'), 'r') as file:
        professions = json.load(file)
        return professions


def get_student_by_pk(pk):
    """Получает словарь с данными студента по его pk
    """
    for student in load_students():
        if pk == student["pk"]:
            return student


def get_profession_by_title(title):
    """Получает словарь с инфо о профе по названию
    """
    for profession in load_professions():
        if title.lower() == profession["title"].lower():
            return profession


def check_fitness(student, profession):
    """Формирует словарь навыков
    """
    student_skills = set(student['skills'])
    profession_skills = set(profession['skills'])
    has_skills = student_skills.intersection(profession_skills)
    lacks_skills = profession_skills.difference(student_skills)
    percentage = len(student_skills) / len(profession_skills) * 100
    result = {"has": has_skills,
              "lacks": lacks_skills,
              "fit_percent": percentage
              }
    return result

