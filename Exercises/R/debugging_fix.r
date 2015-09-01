					REPORT DATA
Call:
glm(formula = Fix ~ System + Treatment + Lab + Experience + Ability)

Deviance Residuals: 
    Min       1Q   Median       3Q      Max  
-1.6761  -0.7980  -0.2366   0.7974   2.1926  

Coefficients:
                   Estimate Std. Error t value Pr(>|t|)   
(Intercept)          1.3780     0.6123   2.251  0.02958 * 
Systemxml-security  -0.1397     0.3255  -0.429  0.66986   
Treatmentrandom      0.6645     0.3229   2.058  0.04568 * 
Lablab2              0.4310     0.3311   1.302  0.19993   
Experiencemsc        0.8687     0.3589   2.421  0.01978 * 
Abilitylow          -1.8309     0.5556  -3.295  0.00198 **
Abilitymedium       -1.0017     0.4851  -2.065  0.04499 * 
---
Signif. codes:  0 ‘***’ 0.001 ‘**’ 0.01 ‘*’ 0.05 ‘.’ 0.1 ‘ ’ 1

(Dispersion parameter for gaussian family taken to be 1.272075)

    Null deviance: 101.120  on 49  degrees of freedom
Residual deviance:  54.699  on 43  degrees of freedom
AIC: 162.39

Number of Fisher Scoring iterations: 2


					ALESSANDRO DATA
Call:
glm(formula = Fix ~ System + Treatment + Lab + Experience + Ability)

Deviance Residuals: 
    Min       1Q   Median       3Q      Max  
-1.4318  -0.7035  -0.2082   0.8575   2.2506  

Coefficients:
                   Estimate Std. Error t value Pr(>|t|)    
(Intercept)          1.6997     0.5806   2.927 0.005446 ** 
Systemxml-security  -0.2519     0.3087  -0.816 0.418979    
Treatmentrandom      0.6750     0.3062   2.204 0.032895 *  
Lablab2              0.2894     0.3140   0.922 0.361905    
Experiencemsc        0.6823     0.3403   2.005 0.051276 .  
Abilitylow          -1.9625     0.5269  -3.725 0.000565 ***
Abilitymedium       -1.2396     0.4600  -2.695 0.010012 *  
---
Signif. codes:  0 ‘***’ 0.001 ‘**’ 0.01 ‘*’ 0.05 ‘.’ 0.1 ‘ ’ 1

(Dispersion parameter for gaussian family taken to be 1.143892)

    Null deviance: 93.380  on 49  degrees of freedom
Residual deviance: 49.187  on 43  degrees of freedom
AIC: 157.07

Number of Fisher Scoring iterations: 2

						REPORT CONCLUSIONS

TREATEMENT: We can observe that subjects who usedautogen tests showed better effectiveness (i.e., correctly fixed more faults) than subjects who used manually written tests.

ABILITY: We can notice that the high ability and high experience subjects are associated witha line substantially higher than the line for the low ability/experience subjects

EXPERIENCE: high experience subjects improve their performance when using autogen tests much more than lower experience subjects do. In other words, subjects with high experience are better at taking advantage of the higher effectiveness provided by autogen tests.

SYSTEM, LAB: we can notice that System and Lab are not significant factors, thus there is no effect
of the system and no learning effect between the two experimental sessions.
