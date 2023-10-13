from sympy.core.sympify import kernS
import PySimpleGUIQt as sg
import sympy as sy


class AlgebraSolver:
    def __init__(self):
        self.result = ""
        self.layout = [
            [sg.Text("Enter the linear equation"), sg.In(key="lneq")],
            [sg.Button("Evaluate", enable_events=True, key="eval")],
            [sg.Text("Result:"), sg.Text(text="", key="result")],
        ]

    def evaluate_linear(self, expression):
        if len(expression) == 0:
            return "Enter valid expression"
        try:
            exp = expression.split("=")
            sy_exp = kernS(exp[0])
            if exp[1].isdigit():
                req = int(exp[1])
            else:
                req = kernS(exp[1])
        except SyntaxError:
            return "Not a valid expression"
        return sy.solveset(sy.Eq(sy_exp, req))

    def render(self):
        window = sg.Window("Algebra Solver", resizable=True,
                           size=(800, 100)).Layout(self.layout)

        while True:
            event, values = window.Read()
            if event == "eval":
                self.result = self.evaluate_linear(values["lneq"])
                window["result"].update(self.result)
            elif event == sg.WIN_CLOSED or event == "EXIT":
                break


if __name__ == "__main__":
    al = AlgebraSolver()
    al.render()