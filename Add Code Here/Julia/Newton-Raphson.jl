

"""
findroot(func,derivative, startval, tol;step=0.1, maxstep = 100)

Simple implementation of Newton-Raphson Method for polinomials. 
If will try to find the closest root to the starting value. 

It receives the function to evaluate and its derivative as functions. 

"""
function findroot(func,derivative, startval, tol;step=0.1, maxstep = 100)
    if isapprox(derivative(startval),0)
        println("Starting point derivative is zero")
        return
    end
    step = 0;
    oldroot = startval;
    root = Nothing;
    while step < maxstep 
        root = oldroot - func(oldroot)/derivative(oldroot)
        if abs(root-oldroot) < tol 
            break;
        end
        oldroot = root;
        step += 1;
    end
    println("Root found at $(root)")
end