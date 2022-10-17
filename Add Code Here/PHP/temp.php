<?php 
$result = "";
class temperature
{
    var $input;
    var $temp;

    function checkconv($conversion)
    {
        switch($conversion)
        {
            case 'f':
                if($this->temp == 'c'){
                   $result = (9/5*$this->input) + 32;
                }else{
                    $result = $this->input;
                }
            return $result;
            break;

            case 'c':
                if($this->temp == 'f'){
                    $result = ($this->input-32) * (5/9);
                }else{
                    $result = $this->input;
                }
            return $result;
            break;

            default:
            return "Sorry No command found";
        }   
    }
    function getresult($input, $temp, $conv)
    {
        $this->input = $input;
        $this->temp = $temp;
        return $this->checkconv($conv);
    }
}

$cal = new temperature();
if(isset($_POST['submit']))
{   
    $result = $cal->getresult($_POST['input'],$_POST['temp'],$_POST['conv']);
}
?>

<form method="post">
<table align="left">
    <tr>
        <td>Input your Temperature</td>
        <td><input type="text" name="input"></td>
        <td>
            <select name="temp">
                <option value="c">Celcius</option>
                <option value="f">Farenheit</option>
            </select>
        </td>
    </tr>

    <tr>
        <td>Select Conversion</td>
        <td>
            <select name="conv">
                <option value="c">Celcius</option>
                <option value="f">Farenheit</option>
            </select>
        </td>
    </tr>

    <tr>
        <td></td>
        <td><input type="submit" name="submit" value="="></td>
    </tr>

    <tr>
        <td>The Result</td>
        <td><strong><?php echo $result; ?><strong></td>
    </tr>
</table>
</form>