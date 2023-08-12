using .Threads



function disminucion(n)
    valor = 10000000

    @threads for i in 1:n 
        valor -=1
    end 
end 


function disminucion_protegida(n)
    valor = 10000000
    lk = ReentrantLock()

    @threads for i in 1:n 
        lock(lk) do
            valor -=1
        end
    end 
end 



function disminucion_inversa(n)
    valor = 10000000

    @threads for i in 1:n 
        10000000 - i
    end 
end 

@time disminucion(1000000)

@time disminucion_protegida(1000000)

@time disminucion_inversa(1000000)