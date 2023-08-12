using Distributed

function azar(lanzamientos)
    num_caras = 0
    for i = 1:lanzamientos
        num_caras += Int(rand(Bool))
    end
    return num_caras
end

function azarparalelo(lanzamientos)
    num_caras = @distributed (+) for i = 1:lanzamientos
        Int(rand(Bool))

    end
    return num_caras
end



for i = 1:10
    print("paralelo")
    @time begin 
        azarparalelo(10000)
    end 
end


for i = 1:10
    print("normal")
    @time begin 
        
        azar(10000)
    end
end