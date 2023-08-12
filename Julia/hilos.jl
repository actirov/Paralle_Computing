using .Threads


function suma_desprotegida(n)

    arreglo = Int[]
    @threads for i = 1:n
        push!(arreglo, i)
        println("Soy ", Threads.threadid(), " metiendo ", i)

    end
    return sum(arreglo)

end


function suma_protegida(n)
    arreglo = Int[]
    lk = ReentrantLock()

    @threads for i in  1:n
        lock(lk) do
            push!(arreglo, i)
            println("Soy ", Threads.threadid(), " meto ", i)
        end 
    end 
    sum(arreglo)
end
