import ctypes 

deadline_lib = ctypes.CDLL('./res.so') 

deadline_lib.create_deadline.argtypes = [ctypes.c_char_p, ctypes.c_char_p, ctypes.c_char_p,
                                          ctypes.c_int, ctypes.c_int]
deadline_lib.create_deadline.restype = ctypes.c_void_p

deadline_lib.create_periodical.argtypes = [ctypes.c_char_p, ctypes.c_char_p, ctypes.c_char_p,
                                          ctypes.c_int, ctypes.c_int, ctypes.c_int]
deadline_lib.create_periodical.restype = ctypes.c_void_p

deadline_lib.create_planner.argtypes = [ctypes.c_char_p]
deadline_lib.create_planner.restype = ctypes.c_void_p

deadline_lib.create_plan.argtypes = [ctypes.c_void_p]
deadline_lib.create_plan.restype = ctypes.c_void_p

deadline_lib.add_task.argtypes = [ctypes.c_void_p, ctypes.c_void_p]
deadline_lib.add_task.restype = ctypes.c_void_p

deadline_lib.print_plan.argtypes = [ctypes.c_char_p, ctypes.c_void_p]
deadline_lib.print_plan.restype = ctypes.c_void_p

deadline_lib.complete.argtypes = [ctypes.c_char_p, ctypes.c_void_p]
deadline_lib.complete.restype = ctypes.c_int

opr = '0'

def add_task():
	flag = 1
	get_type = input("Веберите тип задания: 1. С крайним сроком 2. Периодическое: ")
	while flag == 1:
		ident = input("Введите идентификатор задания ")
		ident = ctypes.c_char_p(ident.encode('utf-8'))
		text = input("Введите текст задания ")
		t = ctypes.c_char_p(text.encode('utf-8'))
		name = input("Введите имя исполнителя ")
		name = ctypes.c_char_p(name.encode('utf-8'))
		imp = input("Введите важность от 1 до 3 ")
		time = input("Введите время от 0 до 23")
		while True:
			try:
				time = int(time)
				break
			except ValueError:
				print("Ошибка. Введите число от 0 до 23 ")
				time = input("Введите время от 0 до 23 ")
		while ((int(time) < 0) or (int(time) > 23)):
			print ("Ошибка. Введите число от 0 до 23 ")
			time = input("Введите время от 0 до 23 ")
		if get_type == '1':
			flag = 0
		elif get_type == '2':
			period = input("Введите период : ")
			flag = 0
		else:
			print("Ошибка. Выберите верный тип задания. ")
	print("Добавляю задание ")
	if get_type == '1':
		d1 = deadline_lib.create_deadline(ident, t, name, int(imp), int(time))
		if d1 == 0:
			print("Ошибка. Попробуйте заново")
		else:
			plan = deadline_lib.create_plan(d1)
			deadline_lib.add_task(plan, planner)
	elif get_type == '2':
		p1 = deadline_lib.create_periodical(ident, t, name, int(imp), int(time),int(period))
		plan = deadline_lib.create_plan(p1)
		deadline_lib.add_task(plan, planner)
	print("Задание " + text + " добавлено")

def del_task():
	ident = input("Введите идентификатор выполненного задания ")
	ident = ctypes.c_char_p(ident.encode('utf-8'))
	deadline_lib.complete(ident, planner)
	print("Задание удалено!")
	
def show():
	name = input("Введите имя исполнителя, чей план хотите увидеть: ")
	name = ctypes.c_char_p(name.encode('utf-8'))
	deadline_lib.print_plan(name, planner)

day = input("Введите день: ")
day = ctypes.c_char_p(day.encode('utf-8'))
planner = deadline_lib.create_planner(day)
		

while opr != '4':
	opr = input("Выберите действие:" "\n1.Добавить задание\n2.Удалить задание\n3.Показать план\n4. Выйти\n")
	if opr == '1':
		add_task()
	elif opr == '2':
		del_task()
	elif opr == '3':
		show()
	elif opr == '4':
		print("До встречи! ")
		break
	else:
		print("Ошибка. Выберите действие 1-4 ")
		
