# 1. Name:
#      Ervin Martinez
# 2. Assignment Name:
#      Lab 01: Tic-Tac-Toe
# 3. Assignment Description:
#      Play the game of Tic-Tac-Toe
# 4. What was the hardest part? Be as specific as possible.
#      It went well what took the longest was me trying to get the terminal behavior
#      the way I wanted it to be. I haven't played with the terminal ascii escape
#      commands before.
# 5. How long did it take for you to complete the assignment?
#      -6hrs
import json

# The characters used in the Tic-Tac-Too board.
# These are constants and therefore should never have to change.
X = 'X'
O = 'O'
BLANK = ' '

# A blank Tic-Tac-Toe board. We should not need to change this board;
# it is only used to reset the board to blank. This should be the format
# of the code in the JSON file.
blank_board = {  
            "board": [
                BLANK, BLANK, BLANK,
                BLANK, BLANK, BLANK,
                BLANK, BLANK, BLANK ]
        }

def move_cursor_up(lines=1):
    print(f"\033[{lines}A", end='')

def move_cursor_down(lines=1):
    print(f"\033[{lines}B", end='')

def clear_line():
    print("\033[2K", end='')

def read_board(filename):
    '''Read the previously existing board from the file if it exists.'''
    global BLANK, blank_board

    try:
        with open(filename, 'r') as file:
            data = json.load(file)
        blank_board = {"board": [BLANK if cell == "BLANK" else cell for cell in data["board"]]}
        move_cursor_up()
        clear_line()
        file.close()
        return blank_board['board']
    except FileNotFoundError:
        if filename == 'q':
            return 'q'
        else:
            print("No previous game found. New Game Created with name{}".format(filename))
            move_cursor_up()
            clear_line()
            return blank_board['board']

def save_board(filename, board):
    '''Save the current game to a file.'''
    try:
        if filename == 'q':
            return
        else:
            # board_to_save = ["BLANK" if cell == BLANK else cell for cell in board]
            # data = {"board": board_to_save}
            board = {"board": ["BLANK" if cell == BLANK else cell for cell in board]}

            with open(filename, 'w') as file: json.dump(board, file, indent=4)
            file.close()
            print(f"Game saved to {filename}.")
    except FileNotFoundError:
        print(f"File {filename} not found.")
        save_board(input("Enter a file name to save the game, or 'q' to quit: "), board)
    except ValueError:
        print("Invalid input.")
        save_board(input("Enter a file name to save the game, or 'q' to quit: "), board)

def display_board(board):
    '''Display a Tic-Tac-Toe board on the screen in a user-friendly way.'''
    for row in range(3):
        print(" {} | {} | {} ".format(board[row*3], board[row*3+1], board[row*3+2]))
        if row < 2:
            print("---+---+---")
        else: print()

def clear_part_of_screen(num_lines):
    '''Clear part of the screen.'''
    move_cursor_up(num_lines)
    print("\033[0J", end='')

def is_x_turn(board):
    '''Determine whose turn it is.'''
    x_count = 0
    o_count = 0

    for cell in board:
        if cell == X:
            x_count += 1
        elif cell == O:
            o_count += 1
    if x_count < o_count or x_count == o_count:
        return True
    elif x_count > o_count:
        return False

def play_game(board):
    game_init = False
    error_message = 0

    def play_turn(board):
        '''Play a turn of the game.'''
        nonlocal game_init
        nonlocal error_message
        if game_init == False:
            game_init = True
            print()
        else:
            clear_part_of_screen(7 + error_message)
        error_message = 0
        display_board(board)
        player = 'X' if is_x_turn(board) else 'O'

        try:
            cell = input(("It is {}'s turn, enter a cell number: ".format(player)))
            if cell == 'q':
                return False
            elif int(cell) < 1 or int(cell) > 9:
                error_message = 1
                print("That is not a valid cell number. Try again.")
            elif board[int(cell) - 1]!= BLANK:
                error_message = 1
                print("That space is already taken. Try again.")
            else:
                cell = int(cell)
                board[cell - 1] = player
        except ValueError:
            error_message = 1
            print("That is not a valid cell number. Try again.")
        return True
    return play_turn

def game_done(board, message=False):
    '''Determine if the game is finished.
       Note that this function is provided as-is.
       You do not need to edit it in any way.
       If message == True, then we display a message to the user.
       Otherwise, no message is displayed. '''

    # Game is finished if someone has completed a row.
    for row in range(3):
        if board[row * 3] != BLANK and board[row * 3] == board[row * 3 + 1] == board[row * 3 + 2]:
            if message:
                print("The game was won by", board[row * 3])
            return True

    # Game is finished if someone has completed a column.
    for col in range(3):
        if board[col] != BLANK and board[col] == board[3 + col] == board[6 + col]:
            if message:
                print("The game was won by", board[col])
            return True

    # Game is finished if someone has a diagonal.
    if board[4] != BLANK and (board[0] == board[4] == board[8] or
                              board[2] == board[4] == board[6]):
        if message:
            print("The game was won by", board[4])
        return True

    # Game is finished if all the squares are filled.
    tie = True
    for square in board:
        if square == BLANK:
            tie = False
    if tie:
        if message:
            print("The game is a tie!")
        return True

    return False

def main():
    print("***********************************************************************************************")
    print("**********************************  Welcome to Tic-Tac-Toe!  **********************************")
    print("***********************************************************************************************")
    
    # These user-instructions are provided and do not need to be changed.
    print("Enter 'q' to suspend your game. Otherwise, enter a number from 1 to 9")
    print("where the following numbers correspond to the locations on the grid:")
    print(" 1 | 2 | 3 ")
    print("---+---+---")
    print(" 4 | 5 | 6 ")
    print("---+---+---")
    print(" 7 | 8 | 9 \n")

    filename = input("Enter game board file name: ")
    if filename != 'q':
        board = read_board(filename)
        game_running = True
        move_cursor_up(7)
        for i in range(7):
            clear_line()

        print("The current board is:")
        move_cursor_up(1)
        play_a_game = play_game(board)

        while game_running:
            in_play = play_a_game(board)
            end = game_done(board, True)

            if not end and not in_play:
                save_board(filename, board) #input("Enter a file name to save the game, or 'q' to quit: "), board)
                game_running = False
            elif end:
                game_running = False

    
    print("*********************************  Thank you for Playing  *********************************")
    return

if __name__ == "__main__":
    main()