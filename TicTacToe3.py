class TicTacToe:
    def __init__(self):
        self.rows, self.cols = 3, 3
        self.box = [["_" for i in range(self.cols)] for j in range(self.rows)]
        self.gameState = 2

    def printBox(self):
        for j in range(self.rows):
            print(self.box[j][0], self.box[j][1], self.box[j][2])

    def getUser(self):
        empty = False
        print("Your turn")
        while not empty:
            print("Please enter your choice:")
            row = int(input("Row: "))
            while row < 1 or row > 3:
                print("That is an invalid value, please re-enter")
                row = int(input("Row: "))
            col = int(input("Column: "))
            while col < 1 or col > 3:
                print("That is an invalid value, please re-enter")
                col = int(input("Column: "))
        
            if self.box[row - 1][col - 1] == "_":
                empty = True
                self.box[row - 1][col - 1] = "O"
            else:
                print("That is an invalid value, please re-enter")

    def getRandom(self):
        empty = False
        print("Computer's turn:\n")
        import random
        while not empty:
            row = random.randrange(1, 4)
            col = random.randrange(1, 4)
            if self.box[row - 1][col - 1] == "_":
                empty = True
                self.box[row - 1][col - 1] = "X"

    def checkState(self):
        # return -1: player win
        # return 0: draw
        # return 1: computer win
        # return 2: continue
        
        # Check row
        for j in range(3): # row
            if (self.box[j][0] == self.box[j][1] == self.box[j][2] == "O"): return -1
            elif (self.box[j][0] == self.box[j][1] == self.box[j][2] == "X"): return 1
        
        # Check column
        for i in range(3): # column
            if (self.box[0][i] == self.box[1][i] == self.box[2][i] == "O"): return -1
            elif (self.box[0][i] == self.box[1][i] == self.box[2][i] == "X"): return 1
        
        # Check diagonal
        # Top left to bottom right
        if (self.box[0][0] == self.box[1][1] == self.box[2][2] == "O"): return -1
        elif (self.box[0][0] == self.box[1][1] == self.box[2][2] == "X"): return 1
        # Top right to bottom left
        if (self.box[0][2] == self.box[1][1] == self.box[2][0] == "O"): return -1
        elif (self.box[0][2] == self.box[1][1] == self.box[2][0] == "X"): return 1

        # Check empty
        for j in range(3):
            for i in range(3):
                if self.box[j][i] == "_": return 2
        
        # Draw
        return 0

    def play(self):
        print("Tic Tac Toe")
        self.printBox()

        while self.gameState == 2:
            self.getUser()
            self.printBox()
            self.gameState = self.checkState()

            if self.gameState == 2:
                self.getRandom()
                self.printBox()
                self.gameState = self.checkState()

        if self.gameState == -1:
            print("You win!")
        elif self.gameState == 0:
            print("It's a draw!")
        else:
            print("The computer wins!")

game = TicTacToe()
game.play()