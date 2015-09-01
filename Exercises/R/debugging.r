setwd("~/R_work/debugging")
data = read.csv2("all.csv", sep=";", dec=",", header=TRUE)

# Delete useless rows
selected = data[,c("ID","Experiment","Group","System","Treatment","Lab","Experience","Ability", "Time1", "Fix1", "Time2", "Fix2", "Time3", "Fix3", "Time4", "Fix4")]

# Selecting only "All" rows
all = selected[selected$Experiment == "All",]

# Sum column Fix1, Fix2, Fix3, Fix4 and rename them (i.e. generate the column "Fix")
sumna = function(a) sum(a, na.rm=TRUE)
all = cbind(all, apply(all[,c("Fix1","Fix2","Fix3", "Fix4")], 1, sumna)) 
colnames(all)[length(all)] = "Fix"

# Calculate efficiency Fix/(Time1*Fix1 + ... + Time4*Fix4) NA and NaN are converted to 0.
efficiency = function(a) if (a[9] != 0 )a[9]/sumna(c(a[1]*a[2], a[3], a[4], a[5]*a[6], a[7]*a[8])) else 0
alleff = cbind(all, apply(all[,c("Time1","Fix1","Time2","Fix2","Time3","Fix3","Time4","Fix4","Fix")], 1, efficiency)) 
colnames(alleff)[length(alleff)] = "Efficiency"

#Remove NaN 
#alleff = alleff[!(alleff$Efficiency == "NaN"),]

attach(alleff)

#Rename litteral data to integers 
abLevel = function(l) if(l == "low") 1 else if(l == "medium") 2 else if(l == "high") 3
Ability = sapply(alleff$Ability, abLevel)

#GLM
fixModel = glm(Fix ~ System + Treatment + Lab + Experience + Ability)
effModel = glm(Efficiency ~ System + Treatment + Lab + Experience + Ability)

#Draw effectiveness plots
boxplot(Fix ~ Ability, names=c("Low","Medium","High"), xlab="Ability", ylab="Effectiveness")
boxplot(Fix ~ Treatment, xlab="Treatment", ylab="Effectiveness")
interaction.plot(Treatment, alleff$Ability , Fix, trace.label = "Ability")

#Draw efficiency plot
boxplot(Efficiency ~ Ability, names=c("Low","Medium","High"), xlab="Ability", ylab="Efficiency")
boxplot(Efficiency ~ Treatment, xlab="Treatment", ylab="Efficiency")
interaction.plot(Treatment, Ability , Efficiency)

interaction.plot(Treatment, Ability , Efficiency)
interaction.plot(Treatment, alleff$Ability , Efficiency)
interaction.plot(Treatment, alleff$Ability , Efficiency, trace.label = "Ability")

detach(allef)

