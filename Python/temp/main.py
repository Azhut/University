import utils

user_answer_student_pk = int(input("Введите номер студента:\n"))

student = utils.get_student_by_pk(user_answer_student_pk)
if student is not None:
    print(student["full_name"])
    result = ', '.join(str(item) for item in student["skills"])
    print(result)
else:
    print("У нас нет такого студента")
    quit(20)

user_answer_profession = input(f"Выберете специальность для оценки студента {student['full_name']}\n")

profession = utils.get_profession_by_title(user_answer_profession)

if profession is not None:

    fitness = utils.check_fitness(student, profession)
    print(f"Пригодность: {fitness['fit_percent']}")

    has_skill = ', '.join(str(item) for item in fitness["has"])
    print(f"{student['full_name']} знает: {has_skill}")

    lacks = ', '.join(str(item) for item in fitness["lacks"])
    print(f"{student['full_name']} не знает: {lacks}")


else:
    print("У нас нет такой специальности")
