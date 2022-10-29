import 'Questions.dart';

class QCuizWork {
  int _onQuestion = 0;

  final List<Questions> _QuestionBank = [
    Questions(
        "1. C programs are converted into machine language with the help of a program called Editor.",
        false),
    Questions("2. Spaces and commas are allowed in a variable name.", false),
    Questions(
        "3. The maximum value that an integer constant can have varies from one compiler to another.",
        true),
    Questions(
        "4. A real constant in C can be expressed in both Fractional and Exponential forms.",
        true),
    Questions(
        "5. Only character or integer can be used in switch statement.", false),
    Questions("6. The return type of malloc function is void.", false),
    Questions("7. #define is known as preprocessor compiler directive.", true),
    Questions("8. Algorithm is the graphical representation of logic.", false),
    Questions("9. sizeof( ) is a function that returns the size of a variable.",
        false),
    Questions(
        "10. The ++ operator increments the operand by 1, whereas, the -- operator decrements it by 1.",
        true)
  ];

  void restart() {
    _onQuestion = 0;
  }

  void getno() {
    if (_onQuestion < _QuestionBank.length - 1) {
      _onQuestion++;
    }
  }

  String getQue() {
    return _QuestionBank[_onQuestion].Que;
  }

  bool getans() {
    return _QuestionBank[_onQuestion].Answers;
  }
}
