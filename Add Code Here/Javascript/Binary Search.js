function binary_search(x,f)
{
    var l = 0;
    var h = x.length-1;
    var flag = false;

    while(l<h)
    {
        let mid = Math.floor(((l+h) / 2));
        if(x[mid] == f)
        {
            flag = true;
            break;
        }else
        { 
            if(x[mid] < f)
            {
                l = mid;
            }else if(x[mid] > f)
            {
                h = mid;
            }
            
        }
    }
    
    if(flag)
    {
        console.log(f + " has been found!");
    }else
    {
        console.log(f + " is not found!");
    }
}

const arr =  [1,3,5,6,7,77,88,99];
var find = 1;
binary_search(arr, find);