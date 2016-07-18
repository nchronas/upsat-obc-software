/ *   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
   *   $ D a t e :                 5 .   F e b r u a r y   2 0 1 3 
   *   $ R e v i s i o n :         V 1 . 0 2 
   * 
   *   P r o j e c t :             C M S I S - R T O S   A P I 
   *   T i t l e :                 c m s i s _ o s . h   h e a d e r   f i l e 
   * 
   *   V e r s i o n   0 . 0 2 
   *         I n i t i a l   P r o p o s a l   P h a s e 
   *   V e r s i o n   0 . 0 3 
   *         o s K e r n e l S t a r t   a d d e d ,   o p t i o n a l   f e a t u r e :   m a i n   s t a r t e d   a s   t h r e a d 
   *         o s S e m a p h o r e s   h a v e   s t a n d a r d   b e h a v i o r 
   *         o s T i m e r C r e a t e   d o e s   n o t   s t a r t   t h e   t i m e r ,   a d d e d   o s T i m e r S t a r t 
   *         o s T h r e a d P a s s   i s   r e n a m e d   t o   o s T h r e a d Y i e l d 
   *   V e r s i o n   1 . 0 1 
   *         S u p p o r t   f o r   C + +   i n t e r f a c e 
   *           -   c o n s t   a t t r i b u t e   r e m o v e d   f r o m   t h e   o s X x x x D e f _ t   t y p e d e f ' s 
   *           -   c o n s t   a t t r i b u t e   a d d e d   t o   t h e   o s X x x x D e f   m a c r o s 
   *         A d d e d :   o s T i m e r D e l e t e ,   o s M u t e x D e l e t e ,   o s S e m a p h o r e D e l e t e 
   *         A d d e d :   o s K e r n e l I n i t i a l i z e 
   *   V e r s i o n   1 . 0 2 
   *         C o n t r o l   f u n c t i o n s   f o r   s h o r t   t i m e o u t s   i n   m i c r o s e c o n d   r e s o l u t i o n : 
   *         A d d e d :   o s K e r n e l S y s T i c k ,   o s K e r n e l S y s T i c k F r e q u e n c y ,   o s K e r n e l S y s T i c k M i c r o S e c 
   *         R e m o v e d :   o s S i g n a l G e t   
   *         
   *     
   * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
   * 
   *   P o r t i o n s   C O P Y R I G H T   2 0 1 5   S T M i c r o e l e c t r o n i c s 
   *   P o r t i o n s   C o p y r i g h t   ( c )   2 0 1 3   A R M   L I M I T E D 
   *   A l l   r i g h t s   r e s e r v e d . 
   *   R e d i s t r i b u t i o n   a n d   u s e   i n   s o u r c e   a n d   b i n a r y   f o r m s ,   w i t h   o r   w i t h o u t 
   *   m o d i f i c a t i o n ,   a r e   p e r m i t t e d   p r o v i d e d   t h a t   t h e   f o l l o w i n g   c o n d i t i o n s   a r e   m e t : 
   *     -   R e d i s t r i b u t i o n s   o f   s o u r c e   c o d e   m u s t   r e t a i n   t h e   a b o v e   c o p y r i g h t 
   *         n o t i c e ,   t h i s   l i s t   o f   c o n d i t i o n s   a n d   t h e   f o l l o w i n g   d i s c l a i m e r . 
   *     -   R e d i s t r i b u t i o n s   i n   b i n a r y   f o r m   m u s t   r e p r o d u c e   t h e   a b o v e   c o p y r i g h t 
   *         n o t i c e ,   t h i s   l i s t   o f   c o n d i t i o n s   a n d   t h e   f o l l o w i n g   d i s c l a i m e r   i n   t h e 
   *         d o c u m e n t a t i o n   a n d / o r   o t h e r   m a t e r i a l s   p r o v i d e d   w i t h   t h e   d i s t r i b u t i o n . 
   *     -   N e i t h e r   t h e   n a m e   o f   A R M     n o r   t h e   n a m e s   o f   i t s   c o n t r i b u t o r s   m a y   b e   u s e d 
   *         t o   e n d o r s e   o r   p r o m o t e   p r o d u c t s   d e r i v e d   f r o m   t h i s   s o f t w a r e   w i t h o u t 
   *         s p e c i f i c   p r i o r   w r i t t e n   p e r m i s s i o n . 
   * 
   *   T H I S   S O F T W A R E   I S   P R O V I D E D   B Y   T H E   C O P Y R I G H T   H O L D E R S   A N D   C O N T R I B U T O R S   " A S   I S " 
   *   A N D   A N Y   E X P R E S S   O R   I M P L I E D   W A R R A N T I E S ,   I N C L U D I N G ,   B U T   N O T   L I M I T E D   T O ,   T H E 
   *   I M P L I E D   W A R R A N T I E S   O F   M E R C H A N T A B I L I T Y   A N D   F I T N E S S   F O R   A   P A R T I C U L A R   P U R P O S E 
   *   A R E   D I S C L A I M E D .   I N   N O   E V E N T   S H A L L   C O P Y R I G H T   H O L D E R S   A N D   C O N T R I B U T O R S   B E 
   *   L I A B L E   F O R   A N Y   D I R E C T ,   I N D I R E C T ,   I N C I D E N T A L ,   S P E C I A L ,   E X E M P L A R Y ,   O R 
   *   C O N S E Q U E N T I A L   D A M A G E S   ( I N C L U D I N G ,   B U T   N O T   L I M I T E D   T O ,   P R O C U R E M E N T   O F 
   *   S U B S T I T U T E   G O O D S   O R   S E R V I C E S ;   L O S S   O F   U S E ,   D A T A ,   O R   P R O F I T S ;   O R   B U S I N E S S 
   *   I N T E R R U P T I O N )   H O W E V E R   C A U S E D   A N D   O N   A N Y   T H E O R Y   O F   L I A B I L I T Y ,   W H E T H E R   I N 
   *   C O N T R A C T ,   S T R I C T   L I A B I L I T Y ,   O R   T O R T   ( I N C L U D I N G   N E G L I G E N C E   O R   O T H E R W I S E ) 
   *   A R I S I N G   I N   A N Y   W A Y   O U T   O F   T H E   U S E   O F   T H I S   S O F T W A R E ,   E V E N   I F   A D V I S E D   O F   T H E 
   *   P O S S I B I L I T Y   O F   S U C H   D A M A G E . 
   * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - * / 
 
   / * * 
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
     *   @ f i l e         c m s i s _ o s . h 
     *   @ a u t h o r     M C D   A p p l i c a t i o n   T e a m 
     *   @ d a t e         2 7 - M a r c h - 2 0 1 5 
     *   @ b r i e f       H e a d e r   o f   c m s i s _ o s . c 
     *                     A   n e w   s e t   o f   A P I s   a r e   a d d e d   i n   a d d i t i o n   t o   e x i s t i n g   o n e s ,   t h e s e   A P I s   
     *                     a r e   s p e c i f i c   t o   F r e e R T O S . 
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
     *   @ a t t e n t i o n 
     * 
     *   L i c e n s e d   u n d e r   M C D - S T   L i b e r t y   S W   L i c e n s e   A g r e e m e n t   V 2 ,   ( t h e   " L i c e n s e " ) ; 
     *   Y o u   m a y   n o t   u s e   t h i s   f i l e   e x c e p t   i n   c o m p l i a n c e   w i t h   t h e   L i c e n s e . 
     *   Y o u   m a y   o b t a i n   a   c o p y   o f   t h e   L i c e n s e   a t : 
     * 
     *                 h t t p : / / w w w . s t . c o m / s o f t w a r e _ l i c e n s e _ a g r e e m e n t _ l i b e r t y _ v 2 
     * 
     *   U n l e s s   r e q u i r e d   b y   a p p l i c a b l e   l a w   o r   a g r e e d   t o   i n   w r i t i n g ,   s o f t w a r e   
     *   d i s t r i b u t e d   u n d e r   t h e   L i c e n s e   i s   d i s t r i b u t e d   o n   a n   " A S   I S "   B A S I S ,   
     *   W I T H O U T   W A R R A N T I E S   O R   C O N D I T I O N S   O F   A N Y   K I N D ,   e i t h e r   e x p r e s s   o r   i m p l i e d . 
     *   S e e   t h e   L i c e n s e   f o r   t h e   s p e c i f i c   l a n g u a g e   g o v e r n i n g   p e r m i s s i o n s   a n d 
     *   l i m i t a t i o n s   u n d e r   t h e   L i c e n s e . 
     * 
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
     * /   
 
   # i f       d e f i n e d   (   _ _ C C _ A R M   ) 
     # d e f i n e   _ _ A S M                         _ _ a s m                                                                             / * ! <   a s m   k e y w o r d   f o r   A R M   C o m p i l e r                     * / 
     # d e f i n e   _ _ I N L I N E                   _ _ i n l i n e                                                                       / * ! <   i n l i n e   k e y w o r d   f o r   A R M   C o m p i l e r               * / 
     # d e f i n e   _ _ S T A T I C _ I N L I N E     s t a t i c   _ _ i n l i n e 
 # e l i f   d e f i n e d   (   _ _ I C C A R M _ _   ) 
     # d e f i n e   _ _ A S M                         _ _ a s m                                                                             / * ! <   a s m   k e y w o r d   f o r   I A R   C o m p i l e r                     * / 
     # d e f i n e   _ _ I N L I N E                   i n l i n e                                                                           / * ! <   i n l i n e   k e y w o r d   f o r   I A R   C o m p i l e r .   O n l y   a v a i l a b l e   i n   H i g h   o p t i m i z a t i o n   m o d e !   * / 
     # d e f i n e   _ _ S T A T I C _ I N L I N E     s t a t i c   i n l i n e 
 # e l i f   d e f i n e d   (   _ _ G N U C _ _   ) 
     # d e f i n e   _ _ A S M                         _ _ a s m                                                                             / * ! <   a s m   k e y w o r d   f o r   G N U   C o m p i l e r                     * / 
     # d e f i n e   _ _ I N L I N E                   i n l i n e                                                                           / * ! <   i n l i n e   k e y w o r d   f o r   G N U   C o m p i l e r               * / 
     # d e f i n e   _ _ S T A T I C _ I N L I N E     s t a t i c   i n l i n e 
 # e n d i f 
 
 # i n c l u d e   < s t d i n t . h > 
 # i n c l u d e   < s t d d e f . h > 
 # i n c l u d e   " c o r e _ c m F u n c . h " 
 	 
 # i n c l u d e   " S E G G E R _ S Y S V I E W _ F r e e R T O S . h " 
 # i n c l u d e   " F r e e R T O S . h " 
 # i n c l u d e   " t a s k . h " 
 # i n c l u d e   " t i m e r s . h " 
 # i n c l u d e   " q u e u e . h " 
 # i n c l u d e   " s e m p h r . h " 
 # i n c l u d e   " e v e n t _ g r o u p s . h " 
 
 / * * 
 \ p a g e   c m s i s _ o s _ h   H e a d e r   F i l e   T e m p l a t e :   c m s i s _ o s . h 
 
 T h e   f i l e   \ b   c m s i s _ o s . h   i s   a   t e m p l a t e   h e a d e r   f i l e   f o r   a   C M S I S - R T O S   c o m p l i a n t   R e a l - T i m e   O p e r a t i n g   S y s t e m   ( R T O S ) . 
 E a c h   R T O S   t h a t   i s   c o m p l i a n t   w i t h   C M S I S - R T O S   s h a l l   p r o v i d e   a   s p e c i f i c   \ b   c m s i s _ o s . h   h e a d e r   f i l e   t h a t   r e p r e s e n t s 
 i t s   i m p l e m e n t a t i o n . 
 
 T h e   f i l e   c m s i s _ o s . h   c o n t a i n s : 
   -   C M S I S - R T O S   A P I   f u n c t i o n   d e f i n i t i o n s 
   -   s t r u c t   d e f i n i t i o n s   f o r   p a r a m e t e r s   a n d   r e t u r n   t y p e s 
   -   s t a t u s   a n d   p r i o r i t y   v a l u e s   u s e d   b y   C M S I S - R T O S   A P I   f u n c t i o n s 
   -   m a c r o s   f o r   d e f i n i n g   t h r e a d s   a n d   o t h e r   k e r n e l   o b j e c t s 
 
 
 < b > N a m e   c o n v e n t i o n s   a n d   h e a d e r   f i l e   m o d i f i c a t i o n s < / b > 
 
 A l l   d e f i n i t i o n s   a r e   p r e f i x e d   w i t h   \ b   o s   t o   g i v e   a n   u n i q u e   n a m e   s p a c e   f o r   C M S I S - R T O S   f u n c t i o n s . 
 D e f i n i t i o n s   t h a t   a r e   p r e f i x e d   \ b   o s _   a r e   n o t   u s e d   i n   t h e   a p p l i c a t i o n   c o d e   b u t   l o c a l   t o   t h i s   h e a d e r   f i l e . 
 A l l   d e f i n i t i o n s   a n d   f u n c t i o n s   t h a t   b e l o n g   t o   a   m o d u l e   a r e   g r o u p e d   a n d   h a v e   a   c o m m o n   p r e f i x ,   i . e .   \ b   o s T h r e a d . 
 
 D e f i n i t i o n s   t h a t   a r e   m a r k e d   w i t h   < b > C A N   B E   C H A N G E D < / b >   c a n   b e   a d a p t e d   t o w a r d s   t h e   n e e d s   o f   t h e   a c t u a l   C M S I S - R T O S   i m p l e m e n t a t i o n . 
 T h e s e   d e f i n i t i o n s   c a n   b e   s p e c i f i c   t o   t h e   u n d e r l y i n g   R T O S   k e r n e l . 
 
 D e f i n i t i o n s   t h a t   a r e   m a r k e d   w i t h   < b > M U S T   R E M A I N   U N C H A N G E D < / b >   c a n n o t   b e   a l t e r e d .   O t h e r w i s e   t h e   C M S I S - R T O S   i m p l e m e n t a t i o n   i s   n o   l o n g e r 
 c o m p l i a n t   t o   t h e   s t a n d a r d .   N o t e   t h a t   s o m e   f u n c t i o n s   a r e   o p t i o n a l   a n d   n e e d   n o t   t o   b e   p r o v i d e d   b y   e v e r y   C M S I S - R T O S   i m p l e m e n t a t i o n . 
 
 
 < b > F u n c t i o n   c a l l s   f r o m   i n t e r r u p t   s e r v i c e   r o u t i n e s < / b > 
 
 T h e   f o l l o w i n g   C M S I S - R T O S   f u n c t i o n s   c a n   b e   c a l l e d   f r o m   t h r e a d s   a n d   i n t e r r u p t   s e r v i c e   r o u t i n e s   ( I S R ) : 
     -   \ r e f   o s S i g n a l S e t 
     -   \ r e f   o s S e m a p h o r e R e l e a s e 
     -   \ r e f   o s P o o l A l l o c ,   \ r e f   o s P o o l C A l l o c ,   \ r e f   o s P o o l F r e e 
     -   \ r e f   o s M e s s a g e P u t ,   \ r e f   o s M e s s a g e G e t 
     -   \ r e f   o s M a i l A l l o c ,   \ r e f   o s M a i l C A l l o c ,   \ r e f   o s M a i l G e t ,   \ r e f   o s M a i l P u t ,   \ r e f   o s M a i l F r e e 
 
 F u n c t i o n s   t h a t   c a n n o t   b e   c a l l e d   f r o m   a n   I S R   a r e   v e r i f y i n g   t h e   i n t e r r u p t   s t a t u s   a n d   r e t u r n   i n   c a s e   t h a t   t h e y   a r e   c a l l e d 
 f r o m   a n   I S R   c o n t e x t   t h e   s t a t u s   c o d e   \ b   o s E r r o r I S R .   I n   s o m e   i m p l e m e n t a t i o n s   t h i s   c o n d i t i o n   m i g h t   b e   c a u g h t   u s i n g   t h e   H A R D   F A U L T   v e c t o r . 
 
 S o m e   C M S I S - R T O S   i m p l e m e n t a t i o n s   s u p p o r t   C M S I S - R T O S   f u n c t i o n   c a l l s   f r o m   m u l t i p l e   I S R   a t   t h e   s a m e   t i m e . 
 I f   t h i s   i s   i m p o s s i b l e ,   t h e   C M S I S - R T O S   r e j e c t s   c a l l s   b y   n e s t e d   I S R   f u n c t i o n s   w i t h   t h e   s t a t u s   c o d e   \ b   o s E r r o r I S R R e c u r s i v e . 
 
 
 < b > D e f i n e   a n d   r e f e r e n c e   o b j e c t   d e f i n i t i o n s < / b > 
 
 W i t h   < b > \ # d e f i n e   o s O b j e c t s E x t e r n a l < / b >   o b j e c t s   a r e   d e f i n e d   a s   e x t e r n a l   s y m b o l s .   T h i s   a l l o w s   t o   c r e a t e   a   c o n s i s t e n t   h e a d e r   f i l e 
 t h a t   i s   u s e d   t h r o u g h o u t   a   p r o j e c t   a s   s h o w n   b e l o w : 
 
 < i > H e a d e r   F i l e < / i > 
 \ c o d e 
 # i n c l u d e   < c m s i s _ o s . h >                                                                                   / /   C M S I S   R T O S   h e a d e r   f i l e 
 
 / /   T h r e a d   d e f i n i t i o n 
 e x t e r n   v o i d   t h r e a d _ s a m p l e   ( v o i d   c o n s t   * a r g u m e n t ) ;                           / /   f u n c t i o n   p r o t o t y p e 
 o s T h r e a d D e f   ( t h r e a d _ s a m p l e ,   o s P r i o r i t y B e l o w N o r m a l ,   1 ,   1 0 0 ) ; 
 
 / /   P o o l   d e f i n i t i o n 
 o s P o o l D e f ( M y P o o l ,   1 0 ,   l o n g ) ; 
 \ e n d c o d e 
 
 
 T h i s   h e a d e r   f i l e   d e f i n e s   a l l   o b j e c t s   w h e n   i n c l u d e d   i n   a   C / C + +   s o u r c e   f i l e .   W h e n   < b > \ # d e f i n e   o s O b j e c t s E x t e r n a l < / b >   i s 
 p r e s e n t   b e f o r e   t h e   h e a d e r   f i l e ,   t h e   o b j e c t s   a r e   d e f i n e d   a s   e x t e r n a l   s y m b o l s .   A   s i n g l e   c o n s i s t e n t   h e a d e r   f i l e   c a n   t h e r e f o r e   b e 
 u s e d   t h r o u g h o u t   t h e   w h o l e   p r o j e c t . 
 
 < i > E x a m p l e < / i > 
 \ c o d e 
 # i n c l u d e   " o s O b j e c t s . h "           / /   D e f i n i t i o n   o f   t h e   C M S I S - R T O S   o b j e c t s 
 \ e n d c o d e 
 
 \ c o d e 
 # d e f i n e   o s O b j e c t E x t e r n a l       / /   O b j e c t s   w i l l   b e   d e f i n e d   a s   e x t e r n a l   s y m b o l s 
 # i n c l u d e   " o s O b j e c t s . h "           / /   R e f e r e n c e   t o   t h e   C M S I S - R T O S   o b j e c t s 
 \ e n d c o d e 
 
 * / 
 
 # i f n d e f   _ C M S I S _ O S _ H 
 # d e f i n e   _ C M S I S _ O S _ H 
 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s C M S I S   i d e n t i f i e s   t h e   C M S I S - R T O S   A P I   v e r s i o n . 
 # d e f i n e   o s C M S I S                       0 x 1 0 0 0 2             / / / <   A P I   v e r s i o n   ( m a i n   [ 3 1 : 1 6 ]   . s u b   [ 1 5 : 0 ] ) 
 
 / / /   \ n o t e   C A N   B E   C H A N G E D :   \ b   o s C M S I S _ K E R N E L   i d e n t i f i e s   t h e   u n d e r l y i n g   R T O S   k e r n e l   a n d   v e r s i o n   n u m b e r . 
 # d e f i n e   o s C M S I S _ K E R N E L         0 x 1 0 0 0 0 	       / / / <   R T O S   i d e n t i f i c a t i o n   a n d   v e r s i o n   ( m a i n   [ 3 1 : 1 6 ]   . s u b   [ 1 5 : 0 ] ) 
 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s K e r n e l S y s t e m I d   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 # d e f i n e   o s K e r n e l S y s t e m I d   " K E R N E L   V 1 . 0 0 "       / / / <   R T O S   i d e n t i f i c a t i o n   s t r i n g 
 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s F e a t u r e _ x x x   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 # d e f i n e   o s F e a t u r e _ M a i n T h r e a d       1               / / / <   m a i n   t h r e a d             1 = m a i n   c a n   b e   t h r e a d ,   0 = n o t   a v a i l a b l e 
 # d e f i n e   o s F e a t u r e _ P o o l                   1               / / / <   M e m o r y   P o o l s :         1 = a v a i l a b l e ,   0 = n o t   a v a i l a b l e 
 # d e f i n e   o s F e a t u r e _ M a i l Q                 1               / / / <   M a i l   Q u e u e s :           1 = a v a i l a b l e ,   0 = n o t   a v a i l a b l e 
 # d e f i n e   o s F e a t u r e _ M e s s a g e Q           1               / / / <   M e s s a g e   Q u e u e s :     1 = a v a i l a b l e ,   0 = n o t   a v a i l a b l e 
 # d e f i n e   o s F e a t u r e _ S i g n a l s             8               / / / <   m a x i m u m   n u m b e r   o f   S i g n a l   F l a g s   a v a i l a b l e   p e r   t h r e a d 
 # d e f i n e   o s F e a t u r e _ S e m a p h o r e         1             / / / <   o s F e a t u r e _ S e m a p h o r e   f u n c t i o n :   1 = a v a i l a b l e ,   0 = n o t   a v a i l a b l e 
 # d e f i n e   o s F e a t u r e _ W a i t                   0               / / / <   o s W a i t   f u n c t i o n :   1 = a v a i l a b l e ,   0 = n o t   a v a i l a b l e 
 # d e f i n e   o s F e a t u r e _ S y s T i c k             1               / / / <   o s K e r n e l S y s T i c k   f u n c t i o n s :   1 = a v a i l a b l e ,   0 = n o t   a v a i l a b l e 
 
 # i f d e f     _ _ c p l u s p l u s 
 e x t e r n   " C " 
 { 
 # e n d i f 
 
 
 / /   = = = =   E n u m e r a t i o n ,   s t r u c t u r e s ,   d e f i n e s   = = = = 
 
 / / /   P r i o r i t y   u s e d   f o r   t h r e a d   c o n t r o l . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s P r i o r i t y   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 t y p e d e f   e n u m     { 
     o s P r i o r i t y I d l e                     =   - 3 ,                     / / / <   p r i o r i t y :   i d l e   ( l o w e s t ) 
     o s P r i o r i t y L o w                       =   - 2 ,                     / / / <   p r i o r i t y :   l o w 
     o s P r i o r i t y B e l o w N o r m a l       =   - 1 ,                     / / / <   p r i o r i t y :   b e l o w   n o r m a l 
     o s P r i o r i t y N o r m a l                 =     0 ,                     / / / <   p r i o r i t y :   n o r m a l   ( d e f a u l t ) 
     o s P r i o r i t y A b o v e N o r m a l       =   + 1 ,                     / / / <   p r i o r i t y :   a b o v e   n o r m a l 
     o s P r i o r i t y H i g h                     =   + 2 ,                     / / / <   p r i o r i t y :   h i g h 
     o s P r i o r i t y R e a l t i m e             =   + 3 ,                     / / / <   p r i o r i t y :   r e a l t i m e   ( h i g h e s t ) 
     o s P r i o r i t y E r r o r                   =     0 x 8 4                 / / / <   s y s t e m   c a n n o t   d e t e r m i n e   p r i o r i t y   o r   t h r e a d   h a s   i l l e g a l   p r i o r i t y 
 }   o s P r i o r i t y ; 
 
 / / /   T i m e o u t   v a l u e . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s W a i t F o r e v e r   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 # d e f i n e   o s W a i t F o r e v e r           0 x F F F F F F F F           / / / <   w a i t   f o r e v e r   t i m e o u t   v a l u e 
 
 / / /   S t a t u s   c o d e   v a l u e s   r e t u r n e d   b y   C M S I S - R T O S   f u n c t i o n s . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s S t a t u s   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 t y p e d e f   e n u m     { 
     o s O K                                         =           0 ,               / / / <   f u n c t i o n   c o m p l e t e d ;   n o   e r r o r   o r   e v e n t   o c c u r r e d . 
     o s E v e n t S i g n a l                       =     0 x 0 8 ,               / / / <   f u n c t i o n   c o m p l e t e d ;   s i g n a l   e v e n t   o c c u r r e d . 
     o s E v e n t M e s s a g e                     =     0 x 1 0 ,               / / / <   f u n c t i o n   c o m p l e t e d ;   m e s s a g e   e v e n t   o c c u r r e d . 
     o s E v e n t M a i l                           =     0 x 2 0 ,               / / / <   f u n c t i o n   c o m p l e t e d ;   m a i l   e v e n t   o c c u r r e d . 
     o s E v e n t T i m e o u t                     =     0 x 4 0 ,               / / / <   f u n c t i o n   c o m p l e t e d ;   t i m e o u t   o c c u r r e d . 
     o s E r r o r P a r a m e t e r                 =     0 x 8 0 ,               / / / <   p a r a m e t e r   e r r o r :   a   m a n d a t o r y   p a r a m e t e r   w a s   m i s s i n g   o r   s p e c i f i e d   a n   i n c o r r e c t   o b j e c t . 
     o s E r r o r R e s o u r c e                   =     0 x 8 1 ,               / / / <   r e s o u r c e   n o t   a v a i l a b l e :   a   s p e c i f i e d   r e s o u r c e   w a s   n o t   a v a i l a b l e . 
     o s E r r o r T i m e o u t R e s o u r c e     =     0 x C 1 ,               / / / <   r e s o u r c e   n o t   a v a i l a b l e   w i t h i n   g i v e n   t i m e :   a   s p e c i f i e d   r e s o u r c e   w a s   n o t   a v a i l a b l e   w i t h i n   t h e   t i m e o u t   p e r i o d . 
     o s E r r o r I S R                             =     0 x 8 2 ,               / / / <   n o t   a l l o w e d   i n   I S R   c o n t e x t :   t h e   f u n c t i o n   c a n n o t   b e   c a l l e d   f r o m   i n t e r r u p t   s e r v i c e   r o u t i n e s . 
     o s E r r o r I S R R e c u r s i v e           =     0 x 8 3 ,               / / / <   f u n c t i o n   c a l l e d   m u l t i p l e   t i m e s   f r o m   I S R   w i t h   s a m e   o b j e c t . 
     o s E r r o r P r i o r i t y                   =     0 x 8 4 ,               / / / <   s y s t e m   c a n n o t   d e t e r m i n e   p r i o r i t y   o r   t h r e a d   h a s   i l l e g a l   p r i o r i t y . 
     o s E r r o r N o M e m o r y                   =     0 x 8 5 ,               / / / <   s y s t e m   i s   o u t   o f   m e m o r y :   i t   w a s   i m p o s s i b l e   t o   a l l o c a t e   o r   r e s e r v e   m e m o r y   f o r   t h e   o p e r a t i o n . 
     o s E r r o r V a l u e                         =     0 x 8 6 ,               / / / <   v a l u e   o f   a   p a r a m e t e r   i s   o u t   o f   r a n g e . 
     o s E r r o r O S                               =     0 x F F ,               / / / <   u n s p e c i f i e d   R T O S   e r r o r :   r u n - t i m e   e r r o r   b u t   n o   o t h e r   e r r o r   m e s s a g e   f i t s . 
     o s _ s t a t u s _ r e s e r v e d             =     0 x 7 F F F F F F F     / / / <   p r e v e n t   f r o m   e n u m   d o w n - s i z e   c o m p i l e r   o p t i m i z a t i o n . 
 }   o s S t a t u s ; 
 
 # i f   (   I N C L U D E _ e T a s k G e t S t a t e   = =   1   ) 
 / *   T h r e a d   s t a t e   r e t u r n e d   b y   o s T h r e a d G e t S t a t e   * / 
 t y p e d e f   e n u m   { 
 	 o s T h r e a d R u n n i n g       =   0 x 0 , 	             / *   A   t h r e a d   i s   q u e r y i n g   t h e   s t a t e   o f   i t s e l f ,   s o   m u s t   b e   r u n n i n g .   * / 
 	 o s T h r e a d R e a d y           =   0 x 1   , 	 	 	                 / *   T h e   t h r e a d   b e i n g   q u e r i e d   i s   i n   a   r e a d   o r   p e n d i n g   r e a d y   l i s t .   * / 
 	 o s T h r e a d B l o c k e d       =   0 x 2 , 	 	                 / *   T h e   t h r e a d   b e i n g   q u e r i e d   i s   i n   t h e   B l o c k e d   s t a t e .   * / 
 	 o s T h r e a d S u s p e n d e d   =   0 x 3 , 	             / *   T h e   t h r e a d   b e i n g   q u e r i e d   i s   i n   t h e   S u s p e n d e d   s t a t e ,   o r   i s   i n   t h e   B l o c k e d   s t a t e   w i t h   a n   i n f i n i t e   t i m e   o u t .   * / 
 	 o s T h r e a d D e l e t e d       =   0 x 4 , 	 	                     / *   T h e   t h r e a d   b e i n g   q u e r i e d   h a s   b e e n   d e l e t e d ,   b u t   i t s   T C B   h a s   n o t   y e t   b e e n   f r e e d .   * /       
     o s T h r e a d E r r o r           =   0 x 7 F F F F F F F 
 }   o s T h r e a d S t a t e ; 
 # e n d i f   / *   I N C L U D E _ e T a s k G e t S t a t e   * / 
 
 / / /   T i m e r   t y p e   v a l u e   f o r   t h e   t i m e r   d e f i n i t i o n . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s _ t i m e r _ t y p e   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 t y p e d e f   e n u m     { 
     o s T i m e r O n c e                           =           0 ,               / / / <   o n e - s h o t   t i m e r 
     o s T i m e r P e r i o d i c                   =           1                 / / / <   r e p e a t i n g   t i m e r 
 }   o s _ t i m e r _ t y p e ; 
 
 / / /   E n t r y   p o i n t   o f   a   t h r e a d . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s _ p t h r e a d   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 t y p e d e f   v o i d   ( * o s _ p t h r e a d )   ( v o i d   c o n s t   * a r g u m e n t ) ; 
 
 / / /   E n t r y   p o i n t   o f   a   t i m e r   c a l l   b a c k   f u n c t i o n . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s _ p t i m e r   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 t y p e d e f   v o i d   ( * o s _ p t i m e r )   ( v o i d   c o n s t   * a r g u m e n t ) ; 
 
 / /   > > >   t h e   f o l l o w i n g   d a t a   t y p e   d e f i n i t i o n s   m a y   s h a l l   a d a p t e d   t o w a r d s   a   s p e c i f i c   R T O S 
 
 / / /   T h r e a d   I D   i d e n t i f i e s   t h e   t h r e a d   ( p o i n t e r   t o   a   t h r e a d   c o n t r o l   b l o c k ) . 
 / / /   \ n o t e   C A N   B E   C H A N G E D :   \ b   o s _ t h r e a d _ c b   i s   i m p l e m e n t a t i o n   s p e c i f i c   i n   e v e r y   C M S I S - R T O S . 
 t y p e d e f   T a s k H a n d l e _ t   o s T h r e a d I d ; 
 
 / / /   T i m e r   I D   i d e n t i f i e s   t h e   t i m e r   ( p o i n t e r   t o   a   t i m e r   c o n t r o l   b l o c k ) . 
 / / /   \ n o t e   C A N   B E   C H A N G E D :   \ b   o s _ t i m e r _ c b   i s   i m p l e m e n t a t i o n   s p e c i f i c   i n   e v e r y   C M S I S - R T O S . 
 t y p e d e f   T i m e r H a n d l e _ t   o s T i m e r I d ; 
 
 / / /   M u t e x   I D   i d e n t i f i e s   t h e   m u t e x   ( p o i n t e r   t o   a   m u t e x   c o n t r o l   b l o c k ) . 
 / / /   \ n o t e   C A N   B E   C H A N G E D :   \ b   o s _ m u t e x _ c b   i s   i m p l e m e n t a t i o n   s p e c i f i c   i n   e v e r y   C M S I S - R T O S . 
 t y p e d e f   S e m a p h o r e H a n d l e _ t   o s M u t e x I d ; 
 
 / / /   S e m a p h o r e   I D   i d e n t i f i e s   t h e   s e m a p h o r e   ( p o i n t e r   t o   a   s e m a p h o r e   c o n t r o l   b l o c k ) . 
 / / /   \ n o t e   C A N   B E   C H A N G E D :   \ b   o s _ s e m a p h o r e _ c b   i s   i m p l e m e n t a t i o n   s p e c i f i c   i n   e v e r y   C M S I S - R T O S . 
 t y p e d e f   S e m a p h o r e H a n d l e _ t   o s S e m a p h o r e I d ; 
 
 / / /   P o o l   I D   i d e n t i f i e s   t h e   m e m o r y   p o o l   ( p o i n t e r   t o   a   m e m o r y   p o o l   c o n t r o l   b l o c k ) . 
 / / /   \ n o t e   C A N   B E   C H A N G E D :   \ b   o s _ p o o l _ c b   i s   i m p l e m e n t a t i o n   s p e c i f i c   i n   e v e r y   C M S I S - R T O S . 
 t y p e d e f   s t r u c t   o s _ p o o l _ c b   * o s P o o l I d ; 
 
 / / /   M e s s a g e   I D   i d e n t i f i e s   t h e   m e s s a g e   q u e u e   ( p o i n t e r   t o   a   m e s s a g e   q u e u e   c o n t r o l   b l o c k ) . 
 / / /   \ n o t e   C A N   B E   C H A N G E D :   \ b   o s _ m e s s a g e Q _ c b   i s   i m p l e m e n t a t i o n   s p e c i f i c   i n   e v e r y   C M S I S - R T O S . 
 t y p e d e f   Q u e u e H a n d l e _ t   o s M e s s a g e Q I d ; 
 
 / / /   M a i l   I D   i d e n t i f i e s   t h e   m a i l   q u e u e   ( p o i n t e r   t o   a   m a i l   q u e u e   c o n t r o l   b l o c k ) . 
 / / /   \ n o t e   C A N   B E   C H A N G E D :   \ b   o s _ m a i l Q _ c b   i s   i m p l e m e n t a t i o n   s p e c i f i c   i n   e v e r y   C M S I S - R T O S . 
 t y p e d e f   s t r u c t   o s _ m a i l Q _ c b   * o s M a i l Q I d ; 
 
 
 / / /   T h r e a d   D e f i n i t i o n   s t r u c t u r e   c o n t a i n s   s t a r t u p   i n f o r m a t i o n   o f   a   t h r e a d . 
 / / /   \ n o t e   C A N   B E   C H A N G E D :   \ b   o s _ t h r e a d _ d e f   i s   i m p l e m e n t a t i o n   s p e c i f i c   i n   e v e r y   C M S I S - R T O S . 
 t y p e d e f   s t r u c t   o s _ t h r e a d _ d e f     { 
     c h a r                                       * n a m e ;                 / / / <   T h r e a d   n a m e   
     o s _ p t h r e a d                           p t h r e a d ;             / / / <   s t a r t   a d d r e s s   o f   t h r e a d   f u n c t i o n 
     o s P r i o r i t y                           t p r i o r i t y ;         / / / <   i n i t i a l   t h r e a d   p r i o r i t y 
     u i n t 3 2 _ t                               i n s t a n c e s ;         / / / <   m a x i m u m   n u m b e r   o f   i n s t a n c e s   o f   t h a t   t h r e a d   f u n c t i o n 
     u i n t 3 2 _ t                               s t a c k s i z e ;         / / / <   s t a c k   s i z e   r e q u i r e m e n t s   i n   b y t e s ;   0   i s   d e f a u l t   s t a c k   s i z e 
 }   o s T h r e a d D e f _ t ; 
 
 / / /   T i m e r   D e f i n i t i o n   s t r u c t u r e   c o n t a i n s   t i m e r   p a r a m e t e r s . 
 / / /   \ n o t e   C A N   B E   C H A N G E D :   \ b   o s _ t i m e r _ d e f   i s   i m p l e m e n t a t i o n   s p e c i f i c   i n   e v e r y   C M S I S - R T O S . 
 t y p e d e f   s t r u c t   o s _ t i m e r _ d e f     { 
     o s _ p t i m e r                                   p t i m e r ;         / / / <   s t a r t   a d d r e s s   o f   a   t i m e r   f u n c t i o n 
 }   o s T i m e r D e f _ t ; 
 
 / / /   M u t e x   D e f i n i t i o n   s t r u c t u r e   c o n t a i n s   s e t u p   i n f o r m a t i o n   f o r   a   m u t e x . 
 / / /   \ n o t e   C A N   B E   C H A N G E D :   \ b   o s _ m u t e x _ d e f   i s   i m p l e m e n t a t i o n   s p e c i f i c   i n   e v e r y   C M S I S - R T O S . 
 t y p e d e f   s t r u c t   o s _ m u t e x _ d e f     { 
     u i n t 3 2 _ t                                       d u m m y ;         / / / <   d u m m y   v a l u e . 
 }   o s M u t e x D e f _ t ; 
 
 / / /   S e m a p h o r e   D e f i n i t i o n   s t r u c t u r e   c o n t a i n s   s e t u p   i n f o r m a t i o n   f o r   a   s e m a p h o r e . 
 / / /   \ n o t e   C A N   B E   C H A N G E D :   \ b   o s _ s e m a p h o r e _ d e f   i s   i m p l e m e n t a t i o n   s p e c i f i c   i n   e v e r y   C M S I S - R T O S . 
 t y p e d e f   s t r u c t   o s _ s e m a p h o r e _ d e f     { 
     u i n t 3 2 _ t                                       d u m m y ;         / / / <   d u m m y   v a l u e . 
 }   o s S e m a p h o r e D e f _ t ; 
 
 / / /   D e f i n i t i o n   s t r u c t u r e   f o r   m e m o r y   b l o c k   a l l o c a t i o n . 
 / / /   \ n o t e   C A N   B E   C H A N G E D :   \ b   o s _ p o o l _ d e f   i s   i m p l e m e n t a t i o n   s p e c i f i c   i n   e v e r y   C M S I S - R T O S . 
 t y p e d e f   s t r u c t   o s _ p o o l _ d e f     { 
     u i n t 3 2 _ t                                   p o o l _ s z ;         / / / <   n u m b e r   o f   i t e m s   ( e l e m e n t s )   i n   t h e   p o o l 
     u i n t 3 2 _ t                                   i t e m _ s z ;         / / / <   s i z e   o f   a n   i t e m 
     v o i d                                               * p o o l ;         / / / <   p o i n t e r   t o   m e m o r y   f o r   p o o l 
 }   o s P o o l D e f _ t ; 
 
 / / /   D e f i n i t i o n   s t r u c t u r e   f o r   m e s s a g e   q u e u e . 
 / / /   \ n o t e   C A N   B E   C H A N G E D :   \ b   o s _ m e s s a g e Q _ d e f   i s   i m p l e m e n t a t i o n   s p e c i f i c   i n   e v e r y   C M S I S - R T O S . 
 t y p e d e f   s t r u c t   o s _ m e s s a g e Q _ d e f     { 
     u i n t 3 2 _ t                                 q u e u e _ s z ;         / / / <   n u m b e r   o f   e l e m e n t s   i n   t h e   q u e u e 
     u i n t 3 2 _ t                                   i t e m _ s z ;         / / / <   s i z e   o f   a n   i t e m 
     / / v o i d                                               * p o o l ;         / / / <   m e m o r y   a r r a y   f o r   m e s s a g e s 
 }   o s M e s s a g e Q D e f _ t ; 
 
 / / /   D e f i n i t i o n   s t r u c t u r e   f o r   m a i l   q u e u e . 
 / / /   \ n o t e   C A N   B E   C H A N G E D :   \ b   o s _ m a i l Q _ d e f   i s   i m p l e m e n t a t i o n   s p e c i f i c   i n   e v e r y   C M S I S - R T O S . 
 t y p e d e f   s t r u c t   o s _ m a i l Q _ d e f     { 
     u i n t 3 2 _ t                                 q u e u e _ s z ;         / / / <   n u m b e r   o f   e l e m e n t s   i n   t h e   q u e u e 
     u i n t 3 2 _ t                                   i t e m _ s z ;         / / / <   s i z e   o f   a n   i t e m 
     s t r u c t   o s _ m a i l Q _ c b   * * c b ; 
 }   o s M a i l Q D e f _ t ; 
 
 / / /   E v e n t   s t r u c t u r e   c o n t a i n s   d e t a i l e d   i n f o r m a t i o n   a b o u t   a n   e v e n t . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s _ e v e n t   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 / / /               H o w e v e r   t h e   s t r u c t   m a y   b e   e x t e n d e d   a t   t h e   e n d . 
 t y p e d e f   s t r u c t     { 
     o s S t a t u s                                   s t a t u s ;           / / / <   s t a t u s   c o d e :   e v e n t   o r   e r r o r   i n f o r m a t i o n 
     u n i o n     { 
         u i n t 3 2 _ t                                         v ;           / / / <   m e s s a g e   a s   3 2 - b i t   v a l u e 
         v o i d                                               * p ;           / / / <   m e s s a g e   o r   m a i l   a s   v o i d   p o i n t e r 
         i n t 3 2 _ t                               s i g n a l s ;           / / / <   s i g n a l   f l a g s 
     }   v a l u e ;                                                           / / / <   e v e n t   v a l u e 
     u n i o n     { 
         o s M a i l Q I d                           m a i l _ i d ;           / / / <   m a i l   i d   o b t a i n e d   b y   \ r e f   o s M a i l C r e a t e 
         o s M e s s a g e Q I d               m e s s a g e _ i d ;           / / / <   m e s s a g e   i d   o b t a i n e d   b y   \ r e f   o s M e s s a g e C r e a t e 
     }   d e f ;                                                               / / / <   e v e n t   d e f i n i t i o n 
 }   o s E v e n t ; 
 
 
 / /     = = = =   K e r n e l   C o n t r o l   F u n c t i o n s   = = = = 
 
 / / /   I n i t i a l i z e   t h e   R T O S   K e r n e l   f o r   c r e a t i n g   o b j e c t s . 
 / / /   \ r e t u r n   s t a t u s   c o d e   t h a t   i n d i c a t e s   t h e   e x e c u t i o n   s t a t u s   o f   t h e   f u n c t i o n . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s K e r n e l I n i t i a l i z e   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 o s S t a t u s   o s K e r n e l I n i t i a l i z e   ( v o i d ) ; 
 
 / / /   S t a r t   t h e   R T O S   K e r n e l . 
 / / /   \ r e t u r n   s t a t u s   c o d e   t h a t   i n d i c a t e s   t h e   e x e c u t i o n   s t a t u s   o f   t h e   f u n c t i o n . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s K e r n e l S t a r t   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 o s S t a t u s   o s K e r n e l S t a r t   ( v o i d ) ; 
 
 / / /   C h e c k   i f   t h e   R T O S   k e r n e l   i s   a l r e a d y   s t a r t e d . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s K e r n e l R u n n i n g   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 / / /   \ r e t u r n   0   R T O S   i s   n o t   s t a r t e d ,   1   R T O S   i s   s t a r t e d . 
 i n t 3 2 _ t   o s K e r n e l R u n n i n g ( v o i d ) ; 
 
 # i f   ( d e f i n e d   ( o s F e a t u r e _ S y s T i c k )     & &     ( o s F e a t u r e _ S y s T i c k   ! =   0 ) )           / /   S y s t e m   T i m e r   a v a i l a b l e 
 
 / / /   G e t   t h e   R T O S   k e r n e l   s y s t e m   t i m e r   c o u n t e r   
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s K e r n e l S y s T i c k   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 / / /   \ r e t u r n   R T O S   k e r n e l   s y s t e m   t i m e r   a s   3 2 - b i t   v a l u e   
 u i n t 3 2 _ t   o s K e r n e l S y s T i c k   ( v o i d ) ; 
 
 / / /   T h e   R T O S   k e r n e l   s y s t e m   t i m e r   f r e q u e n c y   i n   H z 
 / / /   \ n o t e   R e f l e c t s   t h e   s y s t e m   t i m e r   s e t t i n g   a n d   i s   t y p i c a l l y   d e f i n e d   i n   a   c o n f i g u r a t i o n   f i l e . 
 # d e f i n e   o s K e r n e l S y s T i c k F r e q u e n c y             ( c o n f i g T I C K _ R A T E _ H Z ) 
 
 / / /   C o n v e r t   a   m i c r o s e c o n d s   v a l u e   t o   a   R T O S   k e r n e l   s y s t e m   t i m e r   v a l u e . 
 / / /   \ p a r a m                   m i c r o s e c           t i m e   v a l u e   i n   m i c r o s e c o n d s . 
 / / /   \ r e t u r n   t i m e   v a l u e   n o r m a l i z e d   t o   t h e   \ r e f   o s K e r n e l S y s T i c k F r e q u e n c y 
 # d e f i n e   o s K e r n e l S y s T i c k M i c r o S e c ( m i c r o s e c )   ( ( ( u i n t 6 4 _ t ) m i c r o s e c   *   ( o s K e r n e l S y s T i c k F r e q u e n c y ) )   /   1 0 0 0 0 0 0 ) 
 
 # e n d i f         / /   S y s t e m   T i m e r   a v a i l a b l e 
 
 / /     = = = =   T h r e a d   M a n a g e m e n t   = = = = 
 
 / / /   C r e a t e   a   T h r e a d   D e f i n i t i o n   w i t h   f u n c t i o n ,   p r i o r i t y ,   a n d   s t a c k   r e q u i r e m e n t s . 
 / / /   \ p a r a m                   n a m e                   n a m e   o f   t h e   t h r e a d   f u n c t i o n . 
 / / /   \ p a r a m                   p r i o r i t y           i n i t i a l   p r i o r i t y   o f   t h e   t h r e a d   f u n c t i o n . 
 / / /   \ p a r a m                   i n s t a n c e s         n u m b e r   o f   p o s s i b l e   t h r e a d   i n s t a n c e s . 
 / / /   \ p a r a m                   s t a c k s z             s t a c k   s i z e   ( i n   b y t e s )   r e q u i r e m e n t s   f o r   t h e   t h r e a d   f u n c t i o n . 
 / / /   \ n o t e   C A N   B E   C H A N G E D :   T h e   p a r a m e t e r s   t o   \ b   o s T h r e a d D e f   s h a l l   b e   c o n s i s t e n t   b u t   t h e 
 / / /               m a c r o   b o d y   i s   i m p l e m e n t a t i o n   s p e c i f i c   i n   e v e r y   C M S I S - R T O S . 
 # i f   d e f i n e d   ( o s O b j e c t s E x t e r n a l )     / /   o b j e c t   i s   e x t e r n a l 
 # d e f i n e   o s T h r e a d D e f ( n a m e ,   t h r e a d ,   p r i o r i t y ,   i n s t a n c e s ,   s t a c k s z )     \ 
 e x t e r n   c o n s t   o s T h r e a d D e f _ t   o s _ t h r e a d _ d e f _ # # n a m e 
 # e l s e                                                         / /   d e f i n e   t h e   o b j e c t 
 # d e f i n e   o s T h r e a d D e f ( n a m e ,   t h r e a d ,   p r i o r i t y ,   i n s t a n c e s ,   s t a c k s z )     \ 
 c o n s t   o s T h r e a d D e f _ t   o s _ t h r e a d _ d e f _ # # n a m e   =   \ 
 {   # n a m e ,   ( t h r e a d ) ,   ( p r i o r i t y ) ,   ( i n s t a n c e s ) ,   ( s t a c k s z )     } 
 # e n d i f 
 
 / / /   A c c e s s   a   T h r e a d   d e f i n i t i o n . 
 / / /   \ p a r a m                   n a m e                     n a m e   o f   t h e   t h r e a d   d e f i n i t i o n   o b j e c t . 
 / / /   \ n o t e   C A N   B E   C H A N G E D :   T h e   p a r a m e t e r   t o   \ b   o s T h r e a d   s h a l l   b e   c o n s i s t e n t   b u t   t h e 
 / / /               m a c r o   b o d y   i s   i m p l e m e n t a t i o n   s p e c i f i c   i n   e v e r y   C M S I S - R T O S . 
 # d e f i n e   o s T h r e a d ( n a m e )     \ 
 & o s _ t h r e a d _ d e f _ # # n a m e 
 
 / / /   C r e a t e   a   t h r e a d   a n d   a d d   i t   t o   A c t i v e   T h r e a d s   a n d   s e t   i t   t o   s t a t e   R E A D Y . 
 / / /   \ p a r a m [ i n ]           t h r e a d _ d e f         t h r e a d   d e f i n i t i o n   r e f e r e n c e d   w i t h   \ r e f   o s T h r e a d . 
 / / /   \ p a r a m [ i n ]           a r g u m e n t             p o i n t e r   t h a t   i s   p a s s e d   t o   t h e   t h r e a d   f u n c t i o n   a s   s t a r t   a r g u m e n t . 
 / / /   \ r e t u r n   t h r e a d   I D   f o r   r e f e r e n c e   b y   o t h e r   f u n c t i o n s   o r   N U L L   i n   c a s e   o f   e r r o r . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s T h r e a d C r e a t e   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 o s T h r e a d I d   o s T h r e a d C r e a t e   ( c o n s t   o s T h r e a d D e f _ t   * t h r e a d _ d e f ,   v o i d   * a r g u m e n t ) ; 
 
 / / /   R e t u r n   t h e   t h r e a d   I D   o f   t h e   c u r r e n t   r u n n i n g   t h r e a d . 
 / / /   \ r e t u r n   t h r e a d   I D   f o r   r e f e r e n c e   b y   o t h e r   f u n c t i o n s   o r   N U L L   i n   c a s e   o f   e r r o r . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s T h r e a d G e t I d   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 o s T h r e a d I d   o s T h r e a d G e t I d   ( v o i d ) ; 
 
 / / /   T e r m i n a t e   e x e c u t i o n   o f   a   t h r e a d   a n d   r e m o v e   i t   f r o m   A c t i v e   T h r e a d s . 
 / / /   \ p a r a m [ i n ]           t h r e a d _ i d       t h r e a d   I D   o b t a i n e d   b y   \ r e f   o s T h r e a d C r e a t e   o r   \ r e f   o s T h r e a d G e t I d . 
 / / /   \ r e t u r n   s t a t u s   c o d e   t h a t   i n d i c a t e s   t h e   e x e c u t i o n   s t a t u s   o f   t h e   f u n c t i o n . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s T h r e a d T e r m i n a t e   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 o s S t a t u s   o s T h r e a d T e r m i n a t e   ( o s T h r e a d I d   t h r e a d _ i d ) ; 
 
 / / /   P a s s   c o n t r o l   t o   n e x t   t h r e a d   t h a t   i s   i n   s t a t e   \ b   R E A D Y . 
 / / /   \ r e t u r n   s t a t u s   c o d e   t h a t   i n d i c a t e s   t h e   e x e c u t i o n   s t a t u s   o f   t h e   f u n c t i o n . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s T h r e a d Y i e l d   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 o s S t a t u s   o s T h r e a d Y i e l d   ( v o i d ) ; 
 
 / / /   C h a n g e   p r i o r i t y   o f   a n   a c t i v e   t h r e a d . 
 / / /   \ p a r a m [ i n ]           t h r e a d _ i d           t h r e a d   I D   o b t a i n e d   b y   \ r e f   o s T h r e a d C r e a t e   o r   \ r e f   o s T h r e a d G e t I d . 
 / / /   \ p a r a m [ i n ]           p r i o r i t y             n e w   p r i o r i t y   v a l u e   f o r   t h e   t h r e a d   f u n c t i o n . 
 / / /   \ r e t u r n   s t a t u s   c o d e   t h a t   i n d i c a t e s   t h e   e x e c u t i o n   s t a t u s   o f   t h e   f u n c t i o n . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s T h r e a d S e t P r i o r i t y   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 o s S t a t u s   o s T h r e a d S e t P r i o r i t y   ( o s T h r e a d I d   t h r e a d _ i d ,   o s P r i o r i t y   p r i o r i t y ) ; 
 
 / / /   G e t   c u r r e n t   p r i o r i t y   o f   a n   a c t i v e   t h r e a d . 
 / / /   \ p a r a m [ i n ]           t h r e a d _ i d           t h r e a d   I D   o b t a i n e d   b y   \ r e f   o s T h r e a d C r e a t e   o r   \ r e f   o s T h r e a d G e t I d . 
 / / /   \ r e t u r n   c u r r e n t   p r i o r i t y   v a l u e   o f   t h e   t h r e a d   f u n c t i o n . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s T h r e a d G e t P r i o r i t y   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 o s P r i o r i t y   o s T h r e a d G e t P r i o r i t y   ( o s T h r e a d I d   t h r e a d _ i d ) ; 
 
 
 / /     = = = =   G e n e r i c   W a i t   F u n c t i o n s   = = = = 
 
 / / /   W a i t   f o r   T i m e o u t   ( T i m e   D e l a y ) . 
 / / /   \ p a r a m [ i n ]           m i l l i s e c             t i m e   d e l a y   v a l u e 
 / / /   \ r e t u r n   s t a t u s   c o d e   t h a t   i n d i c a t e s   t h e   e x e c u t i o n   s t a t u s   o f   t h e   f u n c t i o n . 
 o s S t a t u s   o s D e l a y   ( u i n t 3 2 _ t   m i l l i s e c ) ; 
 
 # i f   ( d e f i n e d   ( o s F e a t u r e _ W a i t )     & &     ( o s F e a t u r e _ W a i t   ! =   0 ) )           / /   G e n e r i c   W a i t   a v a i l a b l e 
 
 / / /   W a i t   f o r   S i g n a l ,   M e s s a g e ,   M a i l ,   o r   T i m e o u t . 
 / / /   \ p a r a m [ i n ]   m i l l i s e c                     t i m e o u t   v a l u e   o r   0   i n   c a s e   o f   n o   t i m e - o u t 
 / / /   \ r e t u r n   e v e n t   t h a t   c o n t a i n s   s i g n a l ,   m e s s a g e ,   o r   m a i l   i n f o r m a t i o n   o r   e r r o r   c o d e . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s W a i t   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 o s E v e n t   o s W a i t   ( u i n t 3 2 _ t   m i l l i s e c ) ; 
 
 # e n d i f     / /   G e n e r i c   W a i t   a v a i l a b l e 
 
 
 / /     = = = =   T i m e r   M a n a g e m e n t   F u n c t i o n s   = = = = 
 / / /   D e f i n e   a   T i m e r   o b j e c t . 
 / / /   \ p a r a m                   n a m e                     n a m e   o f   t h e   t i m e r   o b j e c t . 
 / / /   \ p a r a m                   f u n c t i o n             n a m e   o f   t h e   t i m e r   c a l l   b a c k   f u n c t i o n . 
 / / /   \ n o t e   C A N   B E   C H A N G E D :   T h e   p a r a m e t e r   t o   \ b   o s T i m e r D e f   s h a l l   b e   c o n s i s t e n t   b u t   t h e 
 / / /               m a c r o   b o d y   i s   i m p l e m e n t a t i o n   s p e c i f i c   i n   e v e r y   C M S I S - R T O S . 
 # i f   d e f i n e d   ( o s O b j e c t s E x t e r n a l )     / /   o b j e c t   i s   e x t e r n a l 
 # d e f i n e   o s T i m e r D e f ( n a m e ,   f u n c t i o n )     \ 
 e x t e r n   c o n s t   o s T i m e r D e f _ t   o s _ t i m e r _ d e f _ # # n a m e 
 # e l s e                                                         / /   d e f i n e   t h e   o b j e c t 
 # d e f i n e   o s T i m e r D e f ( n a m e ,   f u n c t i o n )     \ 
 c o n s t   o s T i m e r D e f _ t   o s _ t i m e r _ d e f _ # # n a m e   =   \ 
 {   ( f u n c t i o n )   } 
 # e n d i f 
 
 / / /   A c c e s s   a   T i m e r   d e f i n i t i o n . 
 / / /   \ p a r a m                   n a m e                     n a m e   o f   t h e   t i m e r   o b j e c t . 
 / / /   \ n o t e   C A N   B E   C H A N G E D :   T h e   p a r a m e t e r   t o   \ b   o s T i m e r   s h a l l   b e   c o n s i s t e n t   b u t   t h e 
 / / /               m a c r o   b o d y   i s   i m p l e m e n t a t i o n   s p e c i f i c   i n   e v e r y   C M S I S - R T O S . 
 # d e f i n e   o s T i m e r ( n a m e )   \ 
 & o s _ t i m e r _ d e f _ # # n a m e 
 
 / / /   C r e a t e   a   t i m e r . 
 / / /   \ p a r a m [ i n ]           t i m e r _ d e f           t i m e r   o b j e c t   r e f e r e n c e d   w i t h   \ r e f   o s T i m e r . 
 / / /   \ p a r a m [ i n ]           t y p e                     o s T i m e r O n c e   f o r   o n e - s h o t   o r   o s T i m e r P e r i o d i c   f o r   p e r i o d i c   b e h a v i o r . 
 / / /   \ p a r a m [ i n ]           a r g u m e n t             a r g u m e n t   t o   t h e   t i m e r   c a l l   b a c k   f u n c t i o n . 
 / / /   \ r e t u r n   t i m e r   I D   f o r   r e f e r e n c e   b y   o t h e r   f u n c t i o n s   o r   N U L L   i n   c a s e   o f   e r r o r . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s T i m e r C r e a t e   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 o s T i m e r I d   o s T i m e r C r e a t e   ( c o n s t   o s T i m e r D e f _ t   * t i m e r _ d e f ,   o s _ t i m e r _ t y p e   t y p e ,   v o i d   * a r g u m e n t ) ; 
 
 / / /   S t a r t   o r   r e s t a r t   a   t i m e r . 
 / / /   \ p a r a m [ i n ]           t i m e r _ i d             t i m e r   I D   o b t a i n e d   b y   \ r e f   o s T i m e r C r e a t e . 
 / / /   \ p a r a m [ i n ]           m i l l i s e c             t i m e   d e l a y   v a l u e   o f   t h e   t i m e r . 
 / / /   \ r e t u r n   s t a t u s   c o d e   t h a t   i n d i c a t e s   t h e   e x e c u t i o n   s t a t u s   o f   t h e   f u n c t i o n . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s T i m e r S t a r t   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 o s S t a t u s   o s T i m e r S t a r t   ( o s T i m e r I d   t i m e r _ i d ,   u i n t 3 2 _ t   m i l l i s e c ) ; 
 
 / / /   S t o p   t h e   t i m e r . 
 / / /   \ p a r a m [ i n ]           t i m e r _ i d             t i m e r   I D   o b t a i n e d   b y   \ r e f   o s T i m e r C r e a t e . 
 / / /   \ r e t u r n   s t a t u s   c o d e   t h a t   i n d i c a t e s   t h e   e x e c u t i o n   s t a t u s   o f   t h e   f u n c t i o n . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s T i m e r S t o p   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 o s S t a t u s   o s T i m e r S t o p   ( o s T i m e r I d   t i m e r _ i d ) ; 
 
 / / /   D e l e t e   a   t i m e r   t h a t   w a s   c r e a t e d   b y   \ r e f   o s T i m e r C r e a t e . 
 / / /   \ p a r a m [ i n ]           t i m e r _ i d             t i m e r   I D   o b t a i n e d   b y   \ r e f   o s T i m e r C r e a t e . 
 / / /   \ r e t u r n   s t a t u s   c o d e   t h a t   i n d i c a t e s   t h e   e x e c u t i o n   s t a t u s   o f   t h e   f u n c t i o n . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s T i m e r D e l e t e   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 o s S t a t u s   o s T i m e r D e l e t e   ( o s T i m e r I d   t i m e r _ i d ) ; 
 
 
 / /     = = = =   S i g n a l   M a n a g e m e n t   = = = = 
 
 / / /   S e t   t h e   s p e c i f i e d   S i g n a l   F l a g s   o f   a n   a c t i v e   t h r e a d . 
 / / /   \ p a r a m [ i n ]           t h r e a d _ i d           t h r e a d   I D   o b t a i n e d   b y   \ r e f   o s T h r e a d C r e a t e   o r   \ r e f   o s T h r e a d G e t I d . 
 / / /   \ p a r a m [ i n ]           s i g n a l s               s p e c i f i e s   t h e   s i g n a l   f l a g s   o f   t h e   t h r e a d   t h a t   s h o u l d   b e   s e t . 
 / / /   \ r e t u r n   o s O K   i f   s u c c e s s f u l ,   o s E r r o r O S   i f   f a i l e d . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s S i g n a l S e t   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 i n t 3 2 _ t   o s S i g n a l S e t   ( o s T h r e a d I d   t h r e a d _ i d ,   i n t 3 2 _ t   s i g n a l s ) ; 
 
 / / /   C l e a r   t h e   s p e c i f i e d   S i g n a l   F l a g s   o f   a n   a c t i v e   t h r e a d . 
 / / /   \ p a r a m [ i n ]           t h r e a d _ i d           t h r e a d   I D   o b t a i n e d   b y   \ r e f   o s T h r e a d C r e a t e   o r   \ r e f   o s T h r e a d G e t I d . 
 / / /   \ p a r a m [ i n ]           s i g n a l s               s p e c i f i e s   t h e   s i g n a l   f l a g s   o f   t h e   t h r e a d   t h a t   s h a l l   b e   c l e a r e d . 
 / / /   \ r e t u r n   p r e v i o u s   s i g n a l   f l a g s   o f   t h e   s p e c i f i e d   t h r e a d   o r   0 x 8 0 0 0 0 0 0 0   i n   c a s e   o f   i n c o r r e c t   p a r a m e t e r s . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s S i g n a l C l e a r   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 i n t 3 2 _ t   o s S i g n a l C l e a r   ( o s T h r e a d I d   t h r e a d _ i d ,   i n t 3 2 _ t   s i g n a l s ) ; 
 
 / / /   W a i t   f o r   o n e   o r   m o r e   S i g n a l   F l a g s   t o   b e c o m e   s i g n a l e d   f o r   t h e   c u r r e n t   \ b   R U N N I N G   t h r e a d . 
 / / /   \ p a r a m [ i n ]           s i g n a l s               w a i t   u n t i l   a l l   s p e c i f i e d   s i g n a l   f l a g s   s e t   o r   0   f o r   a n y   s i n g l e   s i g n a l   f l a g . 
 / / /   \ p a r a m [ i n ]           m i l l i s e c             t i m e o u t   v a l u e   o r   0   i n   c a s e   o f   n o   t i m e - o u t . 
 / / /   \ r e t u r n   e v e n t   f l a g   i n f o r m a t i o n   o r   e r r o r   c o d e . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s S i g n a l W a i t   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 o s E v e n t   o s S i g n a l W a i t   ( i n t 3 2 _ t   s i g n a l s ,   u i n t 3 2 _ t   m i l l i s e c ) ; 
 
 
 / /     = = = =   M u t e x   M a n a g e m e n t   = = = = 
 
 / / /   D e f i n e   a   M u t e x . 
 / / /   \ p a r a m                   n a m e                     n a m e   o f   t h e   m u t e x   o b j e c t . 
 / / /   \ n o t e   C A N   B E   C H A N G E D :   T h e   p a r a m e t e r   t o   \ b   o s M u t e x D e f   s h a l l   b e   c o n s i s t e n t   b u t   t h e 
 / / /               m a c r o   b o d y   i s   i m p l e m e n t a t i o n   s p e c i f i c   i n   e v e r y   C M S I S - R T O S . 
 # i f   d e f i n e d   ( o s O b j e c t s E x t e r n a l )     / /   o b j e c t   i s   e x t e r n a l 
 # d e f i n e   o s M u t e x D e f ( n a m e )     \ 
 e x t e r n   c o n s t   o s M u t e x D e f _ t   o s _ m u t e x _ d e f _ # # n a m e 
 # e l s e                                                         / /   d e f i n e   t h e   o b j e c t 
 # d e f i n e   o s M u t e x D e f ( n a m e )     \ 
 c o n s t   o s M u t e x D e f _ t   o s _ m u t e x _ d e f _ # # n a m e   =   {   0   } 
 # e n d i f 
 
 / / /   A c c e s s   a   M u t e x   d e f i n i t i o n . 
 / / /   \ p a r a m                   n a m e                     n a m e   o f   t h e   m u t e x   o b j e c t . 
 / / /   \ n o t e   C A N   B E   C H A N G E D :   T h e   p a r a m e t e r   t o   \ b   o s M u t e x   s h a l l   b e   c o n s i s t e n t   b u t   t h e 
 / / /               m a c r o   b o d y   i s   i m p l e m e n t a t i o n   s p e c i f i c   i n   e v e r y   C M S I S - R T O S . 
 # d e f i n e   o s M u t e x ( n a m e )     \ 
 & o s _ m u t e x _ d e f _ # # n a m e 
 
 / / /   C r e a t e   a n d   I n i t i a l i z e   a   M u t e x   o b j e c t . 
 / / /   \ p a r a m [ i n ]           m u t e x _ d e f           m u t e x   d e f i n i t i o n   r e f e r e n c e d   w i t h   \ r e f   o s M u t e x . 
 / / /   \ r e t u r n   m u t e x   I D   f o r   r e f e r e n c e   b y   o t h e r   f u n c t i o n s   o r   N U L L   i n   c a s e   o f   e r r o r . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s M u t e x C r e a t e   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 o s M u t e x I d   o s M u t e x C r e a t e   ( c o n s t   o s M u t e x D e f _ t   * m u t e x _ d e f ) ; 
 
 / / /   W a i t   u n t i l   a   M u t e x   b e c o m e s   a v a i l a b l e . 
 / / /   \ p a r a m [ i n ]           m u t e x _ i d             m u t e x   I D   o b t a i n e d   b y   \ r e f   o s M u t e x C r e a t e . 
 / / /   \ p a r a m [ i n ]           m i l l i s e c             t i m e o u t   v a l u e   o r   0   i n   c a s e   o f   n o   t i m e - o u t . 
 / / /   \ r e t u r n   s t a t u s   c o d e   t h a t   i n d i c a t e s   t h e   e x e c u t i o n   s t a t u s   o f   t h e   f u n c t i o n . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s M u t e x W a i t   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 o s S t a t u s   o s M u t e x W a i t   ( o s M u t e x I d   m u t e x _ i d ,   u i n t 3 2 _ t   m i l l i s e c ) ; 
 
 / / /   R e l e a s e   a   M u t e x   t h a t   w a s   o b t a i n e d   b y   \ r e f   o s M u t e x W a i t . 
 / / /   \ p a r a m [ i n ]           m u t e x _ i d             m u t e x   I D   o b t a i n e d   b y   \ r e f   o s M u t e x C r e a t e . 
 / / /   \ r e t u r n   s t a t u s   c o d e   t h a t   i n d i c a t e s   t h e   e x e c u t i o n   s t a t u s   o f   t h e   f u n c t i o n . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s M u t e x R e l e a s e   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 o s S t a t u s   o s M u t e x R e l e a s e   ( o s M u t e x I d   m u t e x _ i d ) ; 
 
 / / /   D e l e t e   a   M u t e x   t h a t   w a s   c r e a t e d   b y   \ r e f   o s M u t e x C r e a t e . 
 / / /   \ p a r a m [ i n ]           m u t e x _ i d             m u t e x   I D   o b t a i n e d   b y   \ r e f   o s M u t e x C r e a t e . 
 / / /   \ r e t u r n   s t a t u s   c o d e   t h a t   i n d i c a t e s   t h e   e x e c u t i o n   s t a t u s   o f   t h e   f u n c t i o n . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s M u t e x D e l e t e   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 o s S t a t u s   o s M u t e x D e l e t e   ( o s M u t e x I d   m u t e x _ i d ) ; 
 
 
 / /     = = = =   S e m a p h o r e   M a n a g e m e n t   F u n c t i o n s   = = = = 
 
 # i f   ( d e f i n e d   ( o s F e a t u r e _ S e m a p h o r e )     & &     ( o s F e a t u r e _ S e m a p h o r e   ! =   0 ) )           / /   S e m a p h o r e   a v a i l a b l e 
 
 / / /   D e f i n e   a   S e m a p h o r e   o b j e c t . 
 / / /   \ p a r a m                   n a m e                     n a m e   o f   t h e   s e m a p h o r e   o b j e c t . 
 / / /   \ n o t e   C A N   B E   C H A N G E D :   T h e   p a r a m e t e r   t o   \ b   o s S e m a p h o r e D e f   s h a l l   b e   c o n s i s t e n t   b u t   t h e 
 / / /               m a c r o   b o d y   i s   i m p l e m e n t a t i o n   s p e c i f i c   i n   e v e r y   C M S I S - R T O S . 
 # i f   d e f i n e d   ( o s O b j e c t s E x t e r n a l )     / /   o b j e c t   i s   e x t e r n a l 
 # d e f i n e   o s S e m a p h o r e D e f ( n a m e )     \ 
 e x t e r n   c o n s t   o s S e m a p h o r e D e f _ t   o s _ s e m a p h o r e _ d e f _ # # n a m e 
 # e l s e                                                         / /   d e f i n e   t h e   o b j e c t 
 # d e f i n e   o s S e m a p h o r e D e f ( n a m e )     \ 
 c o n s t   o s S e m a p h o r e D e f _ t   o s _ s e m a p h o r e _ d e f _ # # n a m e   =   {   0   } 
 # e n d i f 
 
 / / /   A c c e s s   a   S e m a p h o r e   d e f i n i t i o n . 
 / / /   \ p a r a m                   n a m e                     n a m e   o f   t h e   s e m a p h o r e   o b j e c t . 
 / / /   \ n o t e   C A N   B E   C H A N G E D :   T h e   p a r a m e t e r   t o   \ b   o s S e m a p h o r e   s h a l l   b e   c o n s i s t e n t   b u t   t h e 
 / / /               m a c r o   b o d y   i s   i m p l e m e n t a t i o n   s p e c i f i c   i n   e v e r y   C M S I S - R T O S . 
 # d e f i n e   o s S e m a p h o r e ( n a m e )     \ 
 & o s _ s e m a p h o r e _ d e f _ # # n a m e 
 
 / / /   C r e a t e   a n d   I n i t i a l i z e   a   S e m a p h o r e   o b j e c t   u s e d   f o r   m a n a g i n g   r e s o u r c e s . 
 / / /   \ p a r a m [ i n ]           s e m a p h o r e _ d e f   s e m a p h o r e   d e f i n i t i o n   r e f e r e n c e d   w i t h   \ r e f   o s S e m a p h o r e . 
 / / /   \ p a r a m [ i n ]           c o u n t                   n u m b e r   o f   a v a i l a b l e   r e s o u r c e s . 
 / / /   \ r e t u r n   s e m a p h o r e   I D   f o r   r e f e r e n c e   b y   o t h e r   f u n c t i o n s   o r   N U L L   i n   c a s e   o f   e r r o r . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s S e m a p h o r e C r e a t e   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 o s S e m a p h o r e I d   o s S e m a p h o r e C r e a t e   ( c o n s t   o s S e m a p h o r e D e f _ t   * s e m a p h o r e _ d e f ,   i n t 3 2 _ t   c o u n t ) ; 
 
 / / /   W a i t   u n t i l   a   S e m a p h o r e   t o k e n   b e c o m e s   a v a i l a b l e . 
 / / /   \ p a r a m [ i n ]           s e m a p h o r e _ i d     s e m a p h o r e   o b j e c t   r e f e r e n c e d   w i t h   \ r e f   o s S e m a p h o r e C r e a t e . 
 / / /   \ p a r a m [ i n ]           m i l l i s e c             t i m e o u t   v a l u e   o r   0   i n   c a s e   o f   n o   t i m e - o u t . 
 / / /   \ r e t u r n   n u m b e r   o f   a v a i l a b l e   t o k e n s ,   o r   - 1   i n   c a s e   o f   i n c o r r e c t   p a r a m e t e r s . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s S e m a p h o r e W a i t   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 i n t 3 2 _ t   o s S e m a p h o r e W a i t   ( o s S e m a p h o r e I d   s e m a p h o r e _ i d ,   u i n t 3 2 _ t   m i l l i s e c ) ; 
 
 / / /   R e l e a s e   a   S e m a p h o r e   t o k e n . 
 / / /   \ p a r a m [ i n ]           s e m a p h o r e _ i d     s e m a p h o r e   o b j e c t   r e f e r e n c e d   w i t h   \ r e f   o s S e m a p h o r e C r e a t e . 
 / / /   \ r e t u r n   s t a t u s   c o d e   t h a t   i n d i c a t e s   t h e   e x e c u t i o n   s t a t u s   o f   t h e   f u n c t i o n . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s S e m a p h o r e R e l e a s e   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 o s S t a t u s   o s S e m a p h o r e R e l e a s e   ( o s S e m a p h o r e I d   s e m a p h o r e _ i d ) ; 
 
 / / /   D e l e t e   a   S e m a p h o r e   t h a t   w a s   c r e a t e d   b y   \ r e f   o s S e m a p h o r e C r e a t e . 
 / / /   \ p a r a m [ i n ]           s e m a p h o r e _ i d     s e m a p h o r e   o b j e c t   r e f e r e n c e d   w i t h   \ r e f   o s S e m a p h o r e C r e a t e . 
 / / /   \ r e t u r n   s t a t u s   c o d e   t h a t   i n d i c a t e s   t h e   e x e c u t i o n   s t a t u s   o f   t h e   f u n c t i o n . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s S e m a p h o r e D e l e t e   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 o s S t a t u s   o s S e m a p h o r e D e l e t e   ( o s S e m a p h o r e I d   s e m a p h o r e _ i d ) ; 
 
 # e n d i f           / /   S e m a p h o r e   a v a i l a b l e 
 
 
 / /     = = = =   M e m o r y   P o o l   M a n a g e m e n t   F u n c t i o n s   = = = = 
 
 # i f   ( d e f i n e d   ( o s F e a t u r e _ P o o l )     & &     ( o s F e a t u r e _ P o o l   ! =   0 ) )     / /   M e m o r y   P o o l   M a n a g e m e n t   a v a i l a b l e 
 
 / / /   \ b r i e f   D e f i n e   a   M e m o r y   P o o l . 
 / / /   \ p a r a m                   n a m e                     n a m e   o f   t h e   m e m o r y   p o o l . 
 / / /   \ p a r a m                   n o                         m a x i m u m   n u m b e r   o f   b l o c k s   ( o b j e c t s )   i n   t h e   m e m o r y   p o o l . 
 / / /   \ p a r a m                   t y p e                     d a t a   t y p e   o f   a   s i n g l e   b l o c k   ( o b j e c t ) . 
 / / /   \ n o t e   C A N   B E   C H A N G E D :   T h e   p a r a m e t e r   t o   \ b   o s P o o l D e f   s h a l l   b e   c o n s i s t e n t   b u t   t h e 
 / / /               m a c r o   b o d y   i s   i m p l e m e n t a t i o n   s p e c i f i c   i n   e v e r y   C M S I S - R T O S . 
 # i f   d e f i n e d   ( o s O b j e c t s E x t e r n a l )     / /   o b j e c t   i s   e x t e r n a l 
 # d e f i n e   o s P o o l D e f ( n a m e ,   n o ,   t y p e )       \ 
 e x t e r n   c o n s t   o s P o o l D e f _ t   o s _ p o o l _ d e f _ # # n a m e 
 # e l s e                                                         / /   d e f i n e   t h e   o b j e c t 
 # d e f i n e   o s P o o l D e f ( n a m e ,   n o ,   t y p e )       \ 
 c o n s t   o s P o o l D e f _ t   o s _ p o o l _ d e f _ # # n a m e   =   \ 
 {   ( n o ) ,   s i z e o f ( t y p e ) ,   N U L L   } 
 # e n d i f 
 
 / / /   \ b r i e f   A c c e s s   a   M e m o r y   P o o l   d e f i n i t i o n . 
 / / /   \ p a r a m                   n a m e                     n a m e   o f   t h e   m e m o r y   p o o l 
 / / /   \ n o t e   C A N   B E   C H A N G E D :   T h e   p a r a m e t e r   t o   \ b   o s P o o l   s h a l l   b e   c o n s i s t e n t   b u t   t h e 
 / / /               m a c r o   b o d y   i s   i m p l e m e n t a t i o n   s p e c i f i c   i n   e v e r y   C M S I S - R T O S . 
 # d e f i n e   o s P o o l ( n a m e )   \ 
 & o s _ p o o l _ d e f _ # # n a m e 
 
 / / /   C r e a t e   a n d   I n i t i a l i z e   a   m e m o r y   p o o l . 
 / / /   \ p a r a m [ i n ]           p o o l _ d e f             m e m o r y   p o o l   d e f i n i t i o n   r e f e r e n c e d   w i t h   \ r e f   o s P o o l . 
 / / /   \ r e t u r n   m e m o r y   p o o l   I D   f o r   r e f e r e n c e   b y   o t h e r   f u n c t i o n s   o r   N U L L   i n   c a s e   o f   e r r o r . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s P o o l C r e a t e   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 o s P o o l I d   o s P o o l C r e a t e   ( c o n s t   o s P o o l D e f _ t   * p o o l _ d e f ) ; 
 
 / / /   A l l o c a t e   a   m e m o r y   b l o c k   f r o m   a   m e m o r y   p o o l . 
 / / /   \ p a r a m [ i n ]           p o o l _ i d               m e m o r y   p o o l   I D   o b t a i n   r e f e r e n c e d   w i t h   \ r e f   o s P o o l C r e a t e . 
 / / /   \ r e t u r n   a d d r e s s   o f   t h e   a l l o c a t e d   m e m o r y   b l o c k   o r   N U L L   i n   c a s e   o f   n o   m e m o r y   a v a i l a b l e . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s P o o l A l l o c   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 v o i d   * o s P o o l A l l o c   ( o s P o o l I d   p o o l _ i d ) ; 
 
 / / /   A l l o c a t e   a   m e m o r y   b l o c k   f r o m   a   m e m o r y   p o o l   a n d   s e t   m e m o r y   b l o c k   t o   z e r o . 
 / / /   \ p a r a m [ i n ]           p o o l _ i d               m e m o r y   p o o l   I D   o b t a i n   r e f e r e n c e d   w i t h   \ r e f   o s P o o l C r e a t e . 
 / / /   \ r e t u r n   a d d r e s s   o f   t h e   a l l o c a t e d   m e m o r y   b l o c k   o r   N U L L   i n   c a s e   o f   n o   m e m o r y   a v a i l a b l e . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s P o o l C A l l o c   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 v o i d   * o s P o o l C A l l o c   ( o s P o o l I d   p o o l _ i d ) ; 
 
 / / /   R e t u r n   a n   a l l o c a t e d   m e m o r y   b l o c k   b a c k   t o   a   s p e c i f i c   m e m o r y   p o o l . 
 / / /   \ p a r a m [ i n ]           p o o l _ i d               m e m o r y   p o o l   I D   o b t a i n   r e f e r e n c e d   w i t h   \ r e f   o s P o o l C r e a t e . 
 / / /   \ p a r a m [ i n ]           b l o c k                   a d d r e s s   o f   t h e   a l l o c a t e d   m e m o r y   b l o c k   t h a t   i s   r e t u r n e d   t o   t h e   m e m o r y   p o o l . 
 / / /   \ r e t u r n   s t a t u s   c o d e   t h a t   i n d i c a t e s   t h e   e x e c u t i o n   s t a t u s   o f   t h e   f u n c t i o n . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s P o o l F r e e   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 o s S t a t u s   o s P o o l F r e e   ( o s P o o l I d   p o o l _ i d ,   v o i d   * b l o c k ) ; 
 
 # e n d i f       / /   M e m o r y   P o o l   M a n a g e m e n t   a v a i l a b l e 
 
 
 / /     = = = =   M e s s a g e   Q u e u e   M a n a g e m e n t   F u n c t i o n s   = = = = 
 
 # i f   ( d e f i n e d   ( o s F e a t u r e _ M e s s a g e Q )     & &     ( o s F e a t u r e _ M e s s a g e Q   ! =   0 ) )           / /   M e s s a g e   Q u e u e s   a v a i l a b l e 
 
 / / /   \ b r i e f   C r e a t e   a   M e s s a g e   Q u e u e   D e f i n i t i o n . 
 / / /   \ p a r a m                   n a m e                     n a m e   o f   t h e   q u e u e . 
 / / /   \ p a r a m                   q u e u e _ s z             m a x i m u m   n u m b e r   o f   m e s s a g e s   i n   t h e   q u e u e . 
 / / /   \ p a r a m                   t y p e                     d a t a   t y p e   o f   a   s i n g l e   m e s s a g e   e l e m e n t   ( f o r   d e b u g g e r ) . 
 / / /   \ n o t e   C A N   B E   C H A N G E D :   T h e   p a r a m e t e r   t o   \ b   o s M e s s a g e Q D e f   s h a l l   b e   c o n s i s t e n t   b u t   t h e 
 / / /               m a c r o   b o d y   i s   i m p l e m e n t a t i o n   s p e c i f i c   i n   e v e r y   C M S I S - R T O S . 
 # i f   d e f i n e d   ( o s O b j e c t s E x t e r n a l )     / /   o b j e c t   i s   e x t e r n a l 
 # d e f i n e   o s M e s s a g e Q D e f ( n a m e ,   q u e u e _ s z ,   t y p e )       \ 
 e x t e r n   c o n s t   o s M e s s a g e Q D e f _ t   o s _ m e s s a g e Q _ d e f _ # # n a m e 
 # e l s e                                                         / /   d e f i n e   t h e   o b j e c t 
 # d e f i n e   o s M e s s a g e Q D e f ( n a m e ,   q u e u e _ s z ,   t y p e )       \ 
 c o n s t   o s M e s s a g e Q D e f _ t   o s _ m e s s a g e Q _ d e f _ # # n a m e   =   \ 
 {   ( q u e u e _ s z ) ,   s i z e o f   ( t y p e )     } 
 # e n d i f 
 
 / / /   \ b r i e f   A c c e s s   a   M e s s a g e   Q u e u e   D e f i n i t i o n . 
 / / /   \ p a r a m                   n a m e                     n a m e   o f   t h e   q u e u e 
 / / /   \ n o t e   C A N   B E   C H A N G E D :   T h e   p a r a m e t e r   t o   \ b   o s M e s s a g e Q   s h a l l   b e   c o n s i s t e n t   b u t   t h e 
 / / /               m a c r o   b o d y   i s   i m p l e m e n t a t i o n   s p e c i f i c   i n   e v e r y   C M S I S - R T O S . 
 # d e f i n e   o s M e s s a g e Q ( n a m e )   \ 
 & o s _ m e s s a g e Q _ d e f _ # # n a m e 
 
 / / /   C r e a t e   a n d   I n i t i a l i z e   a   M e s s a g e   Q u e u e . 
 / / /   \ p a r a m [ i n ]           q u e u e _ d e f           q u e u e   d e f i n i t i o n   r e f e r e n c e d   w i t h   \ r e f   o s M e s s a g e Q . 
 / / /   \ p a r a m [ i n ]           t h r e a d _ i d           t h r e a d   I D   ( o b t a i n e d   b y   \ r e f   o s T h r e a d C r e a t e   o r   \ r e f   o s T h r e a d G e t I d )   o r   N U L L . 
 / / /   \ r e t u r n   m e s s a g e   q u e u e   I D   f o r   r e f e r e n c e   b y   o t h e r   f u n c t i o n s   o r   N U L L   i n   c a s e   o f   e r r o r . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s M e s s a g e C r e a t e   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 o s M e s s a g e Q I d   o s M e s s a g e C r e a t e   ( c o n s t   o s M e s s a g e Q D e f _ t   * q u e u e _ d e f ,   o s T h r e a d I d   t h r e a d _ i d ) ; 
 
 / / /   P u t   a   M e s s a g e   t o   a   Q u e u e . 
 / / /   \ p a r a m [ i n ]           q u e u e _ i d             m e s s a g e   q u e u e   I D   o b t a i n e d   w i t h   \ r e f   o s M e s s a g e C r e a t e . 
 / / /   \ p a r a m [ i n ]           i n f o                     m e s s a g e   i n f o r m a t i o n . 
 / / /   \ p a r a m [ i n ]           m i l l i s e c             t i m e o u t   v a l u e   o r   0   i n   c a s e   o f   n o   t i m e - o u t . 
 / / /   \ r e t u r n   s t a t u s   c o d e   t h a t   i n d i c a t e s   t h e   e x e c u t i o n   s t a t u s   o f   t h e   f u n c t i o n . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s M e s s a g e P u t   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 o s S t a t u s   o s M e s s a g e P u t   ( o s M e s s a g e Q I d   q u e u e _ i d ,   u i n t 3 2 _ t   i n f o ,   u i n t 3 2 _ t   m i l l i s e c ) ; 
 
 / / /   G e t   a   M e s s a g e   o r   W a i t   f o r   a   M e s s a g e   f r o m   a   Q u e u e . 
 / / /   \ p a r a m [ i n ]           q u e u e _ i d             m e s s a g e   q u e u e   I D   o b t a i n e d   w i t h   \ r e f   o s M e s s a g e C r e a t e . 
 / / /   \ p a r a m [ i n ]           m i l l i s e c             t i m e o u t   v a l u e   o r   0   i n   c a s e   o f   n o   t i m e - o u t . 
 / / /   \ r e t u r n   e v e n t   i n f o r m a t i o n   t h a t   i n c l u d e s   s t a t u s   c o d e . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s M e s s a g e G e t   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 o s E v e n t   o s M e s s a g e G e t   ( o s M e s s a g e Q I d   q u e u e _ i d ,   u i n t 3 2 _ t   m i l l i s e c ) ; 
 
 # e n d i f           / /   M e s s a g e   Q u e u e s   a v a i l a b l e 
 
 
 / /     = = = =   M a i l   Q u e u e   M a n a g e m e n t   F u n c t i o n s   = = = = 
 
 # i f   ( d e f i n e d   ( o s F e a t u r e _ M a i l Q )     & &     ( o s F e a t u r e _ M a i l Q   ! =   0 ) )           / /   M a i l   Q u e u e s   a v a i l a b l e 
 
 / / /   \ b r i e f   C r e a t e   a   M a i l   Q u e u e   D e f i n i t i o n . 
 / / /   \ p a r a m                   n a m e                     n a m e   o f   t h e   q u e u e 
 / / /   \ p a r a m                   q u e u e _ s z             m a x i m u m   n u m b e r   o f   m e s s a g e s   i n   q u e u e 
 / / /   \ p a r a m                   t y p e                     d a t a   t y p e   o f   a   s i n g l e   m e s s a g e   e l e m e n t 
 / / /   \ n o t e   C A N   B E   C H A N G E D :   T h e   p a r a m e t e r   t o   \ b   o s M a i l Q D e f   s h a l l   b e   c o n s i s t e n t   b u t   t h e 
 / / /               m a c r o   b o d y   i s   i m p l e m e n t a t i o n   s p e c i f i c   i n   e v e r y   C M S I S - R T O S . 
 # i f   d e f i n e d   ( o s O b j e c t s E x t e r n a l )     / /   o b j e c t   i s   e x t e r n a l 
 # d e f i n e   o s M a i l Q D e f ( n a m e ,   q u e u e _ s z ,   t y p e )   \ 
 e x t e r n   s t r u c t   o s _ m a i l Q _ c b   * o s _ m a i l Q _ c b _ # # n a m e   \ 
 e x t e r n   o s M a i l Q D e f _ t   o s _ m a i l Q _ d e f _ # # n a m e 
 # e l s e                                                         / /   d e f i n e   t h e   o b j e c t 
 # d e f i n e   o s M a i l Q D e f ( n a m e ,   q u e u e _ s z ,   t y p e )   \ 
 s t r u c t   o s _ m a i l Q _ c b   * o s _ m a i l Q _ c b _ # # n a m e ;   \ 
 c o n s t   o s M a i l Q D e f _ t   o s _ m a i l Q _ d e f _ # # n a m e   =     \ 
 {   ( q u e u e _ s z ) ,   s i z e o f   ( t y p e ) ,   ( & o s _ m a i l Q _ c b _ # # n a m e )   } 
 # e n d i f 
 
 / / /   \ b r i e f   A c c e s s   a   M a i l   Q u e u e   D e f i n i t i o n . 
 / / /   \ p a r a m                   n a m e                     n a m e   o f   t h e   q u e u e 
 / / /   \ n o t e   C A N   B E   C H A N G E D :   T h e   p a r a m e t e r   t o   \ b   o s M a i l Q   s h a l l   b e   c o n s i s t e n t   b u t   t h e 
 / / /               m a c r o   b o d y   i s   i m p l e m e n t a t i o n   s p e c i f i c   i n   e v e r y   C M S I S - R T O S . 
 # d e f i n e   o s M a i l Q ( n a m e )     \ 
 & o s _ m a i l Q _ d e f _ # # n a m e 
 
 / / /   C r e a t e   a n d   I n i t i a l i z e   m a i l   q u e u e . 
 / / /   \ p a r a m [ i n ]           q u e u e _ d e f           r e f e r e n c e   t o   t h e   m a i l   q u e u e   d e f i n i t i o n   o b t a i n   w i t h   \ r e f   o s M a i l Q 
 / / /   \ p a r a m [ i n ]           t h r e a d _ i d           t h r e a d   I D   ( o b t a i n e d   b y   \ r e f   o s T h r e a d C r e a t e   o r   \ r e f   o s T h r e a d G e t I d )   o r   N U L L . 
 / / /   \ r e t u r n   m a i l   q u e u e   I D   f o r   r e f e r e n c e   b y   o t h e r   f u n c t i o n s   o r   N U L L   i n   c a s e   o f   e r r o r . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s M a i l C r e a t e   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 o s M a i l Q I d   o s M a i l C r e a t e   ( c o n s t   o s M a i l Q D e f _ t   * q u e u e _ d e f ,   o s T h r e a d I d   t h r e a d _ i d ) ; 
 
 / / /   A l l o c a t e   a   m e m o r y   b l o c k   f r o m   a   m a i l . 
 / / /   \ p a r a m [ i n ]           q u e u e _ i d             m a i l   q u e u e   I D   o b t a i n e d   w i t h   \ r e f   o s M a i l C r e a t e . 
 / / /   \ p a r a m [ i n ]           m i l l i s e c             t i m e o u t   v a l u e   o r   0   i n   c a s e   o f   n o   t i m e - o u t 
 / / /   \ r e t u r n   p o i n t e r   t o   m e m o r y   b l o c k   t h a t   c a n   b e   f i l l e d   w i t h   m a i l   o r   N U L L   i n   c a s e   o f   e r r o r . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s M a i l A l l o c   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 v o i d   * o s M a i l A l l o c   ( o s M a i l Q I d   q u e u e _ i d ,   u i n t 3 2 _ t   m i l l i s e c ) ; 
 
 / / /   A l l o c a t e   a   m e m o r y   b l o c k   f r o m   a   m a i l   a n d   s e t   m e m o r y   b l o c k   t o   z e r o . 
 / / /   \ p a r a m [ i n ]           q u e u e _ i d             m a i l   q u e u e   I D   o b t a i n e d   w i t h   \ r e f   o s M a i l C r e a t e . 
 / / /   \ p a r a m [ i n ]           m i l l i s e c             t i m e o u t   v a l u e   o r   0   i n   c a s e   o f   n o   t i m e - o u t 
 / / /   \ r e t u r n   p o i n t e r   t o   m e m o r y   b l o c k   t h a t   c a n   b e   f i l l e d   w i t h   m a i l   o r   N U L L   i n   c a s e   o f   e r r o r . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s M a i l C A l l o c   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 v o i d   * o s M a i l C A l l o c   ( o s M a i l Q I d   q u e u e _ i d ,   u i n t 3 2 _ t   m i l l i s e c ) ; 
 
 / / /   P u t   a   m a i l   t o   a   q u e u e . 
 / / /   \ p a r a m [ i n ]           q u e u e _ i d             m a i l   q u e u e   I D   o b t a i n e d   w i t h   \ r e f   o s M a i l C r e a t e . 
 / / /   \ p a r a m [ i n ]           m a i l                     m e m o r y   b l o c k   p r e v i o u s l y   a l l o c a t e d   w i t h   \ r e f   o s M a i l A l l o c   o r   \ r e f   o s M a i l C A l l o c . 
 / / /   \ r e t u r n   s t a t u s   c o d e   t h a t   i n d i c a t e s   t h e   e x e c u t i o n   s t a t u s   o f   t h e   f u n c t i o n . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s M a i l P u t   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 o s S t a t u s   o s M a i l P u t   ( o s M a i l Q I d   q u e u e _ i d ,   v o i d   * m a i l ) ; 
 
 / / /   G e t   a   m a i l   f r o m   a   q u e u e . 
 / / /   \ p a r a m [ i n ]           q u e u e _ i d             m a i l   q u e u e   I D   o b t a i n e d   w i t h   \ r e f   o s M a i l C r e a t e . 
 / / /   \ p a r a m [ i n ]           m i l l i s e c             t i m e o u t   v a l u e   o r   0   i n   c a s e   o f   n o   t i m e - o u t 
 / / /   \ r e t u r n   e v e n t   t h a t   c o n t a i n s   m a i l   i n f o r m a t i o n   o r   e r r o r   c o d e . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s M a i l G e t   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 o s E v e n t   o s M a i l G e t   ( o s M a i l Q I d   q u e u e _ i d ,   u i n t 3 2 _ t   m i l l i s e c ) ; 
 
 / / /   F r e e   a   m e m o r y   b l o c k   f r o m   a   m a i l . 
 / / /   \ p a r a m [ i n ]           q u e u e _ i d             m a i l   q u e u e   I D   o b t a i n e d   w i t h   \ r e f   o s M a i l C r e a t e . 
 / / /   \ p a r a m [ i n ]           m a i l                     p o i n t e r   t o   t h e   m e m o r y   b l o c k   t h a t   w a s   o b t a i n e d   w i t h   \ r e f   o s M a i l G e t . 
 / / /   \ r e t u r n   s t a t u s   c o d e   t h a t   i n d i c a t e s   t h e   e x e c u t i o n   s t a t u s   o f   t h e   f u n c t i o n . 
 / / /   \ n o t e   M U S T   R E M A I N   U N C H A N G E D :   \ b   o s M a i l F r e e   s h a l l   b e   c o n s i s t e n t   i n   e v e r y   C M S I S - R T O S . 
 o s S t a t u s   o s M a i l F r e e   ( o s M a i l Q I d   q u e u e _ i d ,   v o i d   * m a i l ) ; 
 
 # e n d i f     / /   M a i l   Q u e u e s   a v a i l a b l e 
 
 / * * * * * * * * * * * * * * * * * * * * * * * * * * *   A d d i t i o n a l   s p e c i f i c   A P I s   t o   F r e e   R T O S   * * * * * * * * * * * * / 
 / * * 
 *   @ b r i e f     H a n d l e s   t h e   t i c k   i n c r e m e n t 
 *   @ p a r a m     n o n e . 
 *   @ r e t v a l   n o n e . 
 * / 
 v o i d   o s S y s t i c k H a n d l e r ( v o i d ) ; 
 
 # i f   (   I N C L U D E _ e T a s k G e t S t a t e   = =   1   ) 
 / * * 
 *   @ b r i e f     O b t a i n   t h e   s t a t e   o f   a n y   t h r e a d . 
 *   @ p a r a m       t h r e a d _ i d       t h r e a d   I D   o b t a i n e d   b y   \ r e f   o s T h r e a d C r e a t e   o r   \ r e f   o s T h r e a d G e t I d . 
 *   @ r e t v a l     t h e   s t a e   o f   t h e   t h r e a d ,   s t a t e s   a r e   e n c o d e d   b y   t h e   o s T h r e a d S t a t e   e n u m e r a t e d   t y p e . 
 * / 
 o s T h r e a d S t a t e   o s T h r e a d G e t S t a t e ( o s T h r e a d I d   t h r e a d _ i d ) ; 
 # e n d i f   / *   I N C L U D E _ e T a s k G e t S t a t e   * / 
 
 # i f   (   I N C L U D E _ e T a s k G e t S t a t e   = =   1   ) 
 / * * 
 *   @ b r i e f   C h e c k   i f   a   t h r e a d   i s   a l r e a d y   s u s p e n d e d   o r   n o t . 
 *   @ p a r a m   t h r e a d _ i d   t h r e a d   I D   o b t a i n e d   b y   \ r e f   o s T h r e a d C r e a t e   o r   \ r e f   o s T h r e a d G e t I d . 
 *   @ r e t v a l   s t a t u s   c o d e   t h a t   i n d i c a t e s   t h e   e x e c u t i o n   s t a t u s   o f   t h e   f u n c t i o n . 
 * / 
 
 o s S t a t u s   o s T h r e a d I s S u s p e n d e d ( o s T h r e a d I d   t h r e a d _ i d ) ; 
 
 # e n d i f   / *   I N C L U D E _ e T a s k G e t S t a t e   * / 
 
 / * * 
 *   @ b r i e f     S u s p e n d   e x e c u t i o n   o f   a   t h r e a d . 
 *   @ p a r a m       t h r e a d _ i d       t h r e a d   I D   o b t a i n e d   b y   \ r e f   o s T h r e a d C r e a t e   o r   \ r e f   o s T h r e a d G e t I d . 
 *   @ r e t v a l     s t a t u s   c o d e   t h a t   i n d i c a t e s   t h e   e x e c u t i o n   s t a t u s   o f   t h e   f u n c t i o n . 
 * / 
 o s S t a t u s   o s T h r e a d S u s p e n d   ( o s T h r e a d I d   t h r e a d _ i d ) ; 
 
 / * * 
 *   @ b r i e f     R e s u m e   e x e c u t i o n   o f   a   s u s p e n d e d   t h r e a d . 
 *   @ p a r a m       t h r e a d _ i d       t h r e a d   I D   o b t a i n e d   b y   \ r e f   o s T h r e a d C r e a t e   o r   \ r e f   o s T h r e a d G e t I d . 
 *   @ r e t v a l     s t a t u s   c o d e   t h a t   i n d i c a t e s   t h e   e x e c u t i o n   s t a t u s   o f   t h e   f u n c t i o n . 
 * / 
 o s S t a t u s   o s T h r e a d R e s u m e   ( o s T h r e a d I d   t h r e a d _ i d ) ; 
 
 / * * 
 *   @ b r i e f     S u s p e n d   e x e c u t i o n   o f   a   a l l   a c t i v e   t h r e a d s . 
 *   @ r e t v a l     s t a t u s   c o d e   t h a t   i n d i c a t e s   t h e   e x e c u t i o n   s t a t u s   o f   t h e   f u n c t i o n . 
 * / 
 o s S t a t u s   o s T h r e a d S u s p e n d A l l   ( v o i d ) ; 
 
 / * * 
 *   @ b r i e f     R e s u m e   e x e c u t i o n   o f   a   a l l   s u s p e n d e d   t h r e a d s . 
 *   @ r e t v a l     s t a t u s   c o d e   t h a t   i n d i c a t e s   t h e   e x e c u t i o n   s t a t u s   o f   t h e   f u n c t i o n . 
 * / 
 o s S t a t u s   o s T h r e a d R e s u m e A l l   ( v o i d ) ; 
 
 / * * 
 *   @ b r i e f     D e l a y   a   t a s k   u n t i l   a   s p e c i f i e d   t i m e 
 *   @ p a r a m       P r e v i o u s W a k e T i m e       P o i n t e r   t o   a   v a r i a b l e   t h a t   h o l d s   t h e   t i m e   a t   w h i c h   t h e   
 *                     t a s k   w a s   l a s t   u n b l o c k e d .   P r e v i o u s W a k e T i m e   m u s t   b e   i n i t i a l i s e d   w i t h   t h e   c u r r e n t   t i m e 
 *                     p r i o r   t o   i t s   f i r s t   u s e   ( P r e v i o u s W a k e T i m e   =   o s K e r n e l S y s T i c k ( )   ) 
 *   @ p a r a m       m i l l i s e c         t i m e   d e l a y   v a l u e 
 *   @ r e t v a l     s t a t u s   c o d e   t h a t   i n d i c a t e s   t h e   e x e c u t i o n   s t a t u s   o f   t h e   f u n c t i o n . 
 * / 
 o s S t a t u s   o s D e l a y U n t i l   ( u i n t 3 2 _ t   * P r e v i o u s W a k e T i m e ,   u i n t 3 2 _ t   m i l l i s e c ) ; 
 
 / * * 
 *   @ b r i e f       L i s t s   a l l   t h e   c u r r e n t   t h r e a d s ,   a l o n g   w i t h   t h e i r   c u r r e n t   s t a t e   
 *                     a n d   s t a c k   u s a g e   h i g h   w a t e r   m a r k . 
 *   @ p a r a m       b u f f e r       A   b u f f e r   i n t o   w h i c h   t h e   a b o v e   m e n t i o n e d   d e t a i l s 
 *                     w i l l   b e   w r i t t e n 
 *   @ r e t v a l     s t a t u s   c o d e   t h a t   i n d i c a t e s   t h e   e x e c u t i o n   s t a t u s   o f   t h e   f u n c t i o n . 
 * / 
 o s S t a t u s   o s T h r e a d L i s t   ( u i n t 8 _ t   * b u f f e r ) ; 
 
 / * * 
 *   @ b r i e f     R e c e i v e   a n   i t e m   f r o m   a   q u e u e   w i t h o u t   r e m o v i n g   t h e   i t e m   f r o m   t h e   q u e u e . 
 *   @ p a r a m     q u e u e _ i d     m e s s a g e   q u e u e   I D   o b t a i n e d   w i t h   \ r e f   o s M e s s a g e C r e a t e . 
 *   @ p a r a m     m i l l i s e c     t i m e o u t   v a l u e   o r   0   i n   c a s e   o f   n o   t i m e - o u t . 
 *   @ r e t v a l   e v e n t   i n f o r m a t i o n   t h a t   i n c l u d e s   s t a t u s   c o d e . 
 * / 
 o s E v e n t   o s M e s s a g e P e e k   ( o s M e s s a g e Q I d   q u e u e _ i d ,   u i n t 3 2 _ t   m i l l i s e c ) ; 
 
 / * * 
 *   @ b r i e f     C r e a t e   a n d   I n i t i a l i z e   a   R e c u r s i v e   M u t e x 
 *   @ p a r a m     m u t e x _ d e f           m u t e x   d e f i n i t i o n   r e f e r e n c e d   w i t h   \ r e f   o s M u t e x . 
 *   @ r e t v a l     m u t e x   I D   f o r   r e f e r e n c e   b y   o t h e r   f u n c t i o n s   o r   N U L L   i n   c a s e   o f   e r r o r . . 
 * / 
 o s M u t e x I d   o s R e c u r s i v e M u t e x C r e a t e   ( c o n s t   o s M u t e x D e f _ t   * m u t e x _ d e f ) ; 
 
 / * * 
 *   @ b r i e f     R e l e a s e   a   R e c u r s i v e   M u t e x 
 *   @ p a r a m       m u t e x _ i d             m u t e x   I D   o b t a i n e d   b y   \ r e f   o s R e c u r s i v e M u t e x C r e a t e . 
 *   @ r e t v a l     s t a t u s   c o d e   t h a t   i n d i c a t e s   t h e   e x e c u t i o n   s t a t u s   o f   t h e   f u n c t i o n . 
 * / 
 o s S t a t u s   o s R e c u r s i v e M u t e x R e l e a s e   ( o s M u t e x I d   m u t e x _ i d ) ; 
 
 / * * 
 *   @ b r i e f     R e l e a s e   a   R e c u r s i v e   M u t e x 
 *   @ p a r a m       m u t e x _ i d         m u t e x   I D   o b t a i n e d   b y   \ r e f   o s R e c u r s i v e M u t e x C r e a t e . 
 *   @ p a r a m   m i l l i s e c             t i m e o u t   v a l u e   o r   0   i n   c a s e   o f   n o   t i m e - o u t . 
 *   @ r e t v a l     s t a t u s   c o d e   t h a t   i n d i c a t e s   t h e   e x e c u t i o n   s t a t u s   o f   t h e   f u n c t i o n . 
 * / 
 o s S t a t u s   o s R e c u r s i v e M u t e x W a i t   ( o s M u t e x I d   m u t e x _ i d ,   u i n t 3 2 _ t   m i l l i s e c ) ; 
 
 # i f d e f     _ _ c p l u s p l u s 
 } 
 # e n d i f 
 
 # e n d i f     / /   _ C M S I S _ O S _ H 
 