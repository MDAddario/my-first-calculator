# Greet user
print('Welcome to my first calculator!')
print('All inputs are of the form: (integer) (operator) (integer).\r\n')

operators = ['+', '-', '*', '/']

while (True):

    # Retrieve input
    num_1 = input('Please input first integer (0, 1, ...): ')
    oper  = input('Please input operator (+, -, *, /): ')
    num_2 = input('Please input second integer (0, 1, ...): ')

    # Validate input
    try:
        num_1 = int(num_1)
    except ValueError:
        print('ERROR: First number is not an integer!')
        continue
    if num_1 < 0 or num_1 > 200:
        print('ERROR: First number must be between 0 and 200.')
        continue

    try:
        num_2 = int(num_2)
    except ValueError:
        print('ERROR: Second number is not an integer!')
        continue
    if num_2 < 0 or num_2 > 200:
        print('ERROR: Second number must be between 0 and 200.')
        continue

    if oper not in operators:
        print('ERROR: Operator not valid, input one of {}'.format(operators))

    # Run the code!
    if oper == operators[0]:
        if num_1 == 0 and num_2 == 0:
            print('Answer: 0\n')
            continue
