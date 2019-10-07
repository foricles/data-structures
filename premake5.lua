workspace "DataStructures"
configurations {"Release", "Debug"}

---------------------------------------------------------------------------------------------------
	project "DataStructures"
		kind "ConsoleApp"
		language "C++"
		
		files
		{
			"src/**.hpp",
			"src/**.cpp",
		}

		filter "configurations:Debug"
			defines { "DEBUG" }
			symbols "On"

		filter "configurations:Release"
			defines { "NDEBUG" }
			optimize "On"