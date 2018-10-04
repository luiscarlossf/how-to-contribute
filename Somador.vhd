library ieee;

use iee.std_logic_1164.all;

entity Somador is 

	generic
	(
		constant N : integer := 4
	);
	
	port
	(
		a : in std_logic_vector(N-1 downto 0);
		b : in std_logic_vector(N-1 downto 0);
		clock : in std_logic;
	);
	
end Somador;

architecture behavior of Somador is

begin

	process(clock,a,b)
	 variable i : integer := 0;
	 variable c : std_logic;
	
    begin
 		for i in 0 to N-1 loop
 			if i = 0 then
 				soma(i) <= a(i) xor b(i);
 				c := a(i) and b(i);
			else
				soma(i) <= a(i) xor b(i) xor c;
				c := (a(i) and b(i)) or (a(i) and c) or (b(i) and c);
			end if;
		end loop;
	end process;
end behavior;   	 
	